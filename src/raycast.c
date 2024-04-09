/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:17:32 by amak              #+#    #+#             */
/*   Updated: 2024/04/10 00:08:49 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	wall_collision(t_ray *ray)
{
	if (ray->hit_vert_wall)
	{
		if (ray->direction.x >= 0)
			ray->wall_texture = WEST;
		else
			ray->wall_texture = EAST;
	}
	else
	{
		if (ray->direction.y >= 0)
			ray->wall_texture = NORTH;
		else
			ray->wall_texture = SOUTH;
	}
}

static void	wall_point(t_ray *ray)
{
	if (ray->wall_texture == WEST)
		ray->wall_hit = (int)ray->y % PX;
	else if (ray->wall_texture == EAST)
		ray->wall_hit = PX - (((int)ray->y % PX) + 1);
	else if (ray->wall_texture == NORTH)
		ray->wall_hit = PX - (((int)ray->x % PX) + 1);
	else if (ray->wall_texture == SOUTH)
		ray->wall_hit = (int)ray->x % PX;
}

void	castray(t_ray *ray, t_player *player, t_cube *file, double angle)
{
	int	hit;

	hit = 0;
	ray->length = 0;
	ray->wall_texture = NONE;
	ray->hit_vert_wall = 0;
	ray->wall_hit = 0;
	ray->y = (double)player->position.y;
	ray->x = (double)player->position.x;
	ray->angle = angle;
	ray->direction.x = cos(angle);
	ray->direction.y = sin(angle);
	while (!hit)
	{
		ray->distance_y = distance_y(ray->y, angle);
		ray->distance_x = distance_x(ray->x, angle);
		increment_ray_length(ray, get_y_step(ray->distance_y, ray->angle),
			get_x_step(ray->distance_x, ray->angle));
		if (check_wall(ray->y, ray->x, file->map))
		{
			wall_collision(ray);
			wall_point(ray);
			hit = 1;
		}
	}
	// printf("--------------------------------\n");
	// printf("py= %d | px= %d | pa= %f \n", (double)player->position.y, (double)player->position.x, player->angle);
	// printf("ry= %d | rx= %d | ra= %f \n", ray->y, ray->x, ray->angle);
	// printf("collision= ");
	// if (ray->wall_texture == NORTH)
	// 	printf("NORTH | \n");
	// if (ray->wall_texture == SOUTH)
	// 		printf("SOUTH | ");
	// if (ray->wall_texture == EAST)
	// 	printf("EAST | ");
	// if (ray->wall_texture == WEST)
	// 	printf("WEST | ");
	// printf("side= %d", ray->hit_vert_wall);
}

void	raycasting(t_cube *file, t_ray *rays)
{
	double	angle;
	double	delta_angle;
	int		pixel_column;

	angle = file->player.angle - (HALF_FOV);
	pixel_column = 0;
	while (pixel_column < SCREEN_WIDTH)
	{
		castray(&rays[pixel_column], &file->player, file, angle);
		delta_angle = file->player.angle - angle;
		if (delta_angle < 0)
			delta_angle += (2 * PI);
		if (delta_angle > (2 * PI))
			delta_angle -= (2 * PI);
		rays[pixel_column].length *= cos(delta_angle);
		angle += (FOV / SCREEN_WIDTH);
		if (angle < 0)
			angle += (2 * PI);
		if (angle > (2 * PI))
			angle -= (2 * PI);
		pixel_column++;
	}
}

void	draw_ray(t_image *image, t_player *player, t_cube *file, double angle)
{
	int		i;
	t_ray	ray;

	i = 1;
	castray(&ray, player, file, angle);
	while (i <= (double)ray.length)
	{
		my_mlx_pixel_put(image, player->position.x + (i * cos(angle)),
			player->position.y + (i * sin(angle)), 0x0000ff00);
		i++;
	}
}
