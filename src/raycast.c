/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:17:32 by amak              #+#    #+#             */
/*   Updated: 2024/04/08 14:39:42 by ftroiter         ###   ########.fr       */
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
/* 	if (ray->wall_texture == WEST)
		ray->wall_hit = ray->y % PX;
	else if (ray->wall_texture == EAST)
		ray->wall_hit = PX - ((ray->y % PX) + 1);
	else if (ray->wall_texture == NORTH)
		ray->wall_hit = PX - ((ray->x % PX) + 1);
	else if (ray->wall_texture == SOUTH)
		ray->wall_hit = ray->x % PX; */
	if (ray->hit_vert_wall)
		ray->wall_hit = (int)ray->y % PX;
	else
		ray->wall_hit = (int)ray->x % PX;
}

void	castray(t_ray *ray, t_player *player, t_file *file, float angle)
{
	int	hit;

	hit = 0;
	ray->length = 0;
	ray->wall_texture = NONE;
	ray->hit_vert_wall = 0;
	ray->wall_hit = 0;
	ray->y = (int)player->position.y;
	ray->x = (int)player->position.x;
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
	printf("wall text= %d | wall point= %d\n", ray->wall_texture, ray->wall_hit);
}

void	draw_ray(t_image *image, t_player *player, t_file *file, float angle)
{
	int		i;
	t_ray	ray;

	i = 1;
	castray(&ray, player, file, angle);
	while (i <= (int)ray.length)
	{
		my_mlx_pixel_put(image, player->position.x + (i * cos(angle)),
			player->position.y + (i * sin(angle)), 0x0000ff00);
		i++;
	}
}
