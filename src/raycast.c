/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:17:32 by amak              #+#    #+#             */
/*   Updated: 2024/04/11 16:40:49 by ftroiter         ###   ########.fr       */
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

void	castray(t_ray *ray, t_player *player, t_cube *cube, double angle)
{
	int	hit;

	hit = 0;
	ray->length = 0;
	ray->wall_texture = 0;
	ray->hit_vert_wall = 0;
	ray->wall_hit = 0;
	ray->y = (double)player->position.y;
	ray->x = (double)player->position.x;
	ray->origin = (t_vector){ray->x, ray->y};
	ray->angle = angle;
	ray->direction.x = cos(angle);
	ray->direction.y = sin(angle);
	ray->is_east = ray->direction.x > 0;
	ray->is_north = ray->direction.y < 0;
	//
	// X      | SIN
	//   x    |
	//     x  |
	// _ _ _ o
	// COS
	//                      90 | PI / 2
  //                      NORTH
  //         	        , - ~ ~ ~ - ,
  //              , '   \---x---/   ' ,  45 | 0.786
  //            ,        \  |  / |      ,
  //           ,          \ | /  |       ,
  // 180 | PI ,            \|/   |cos     ,
  //     WEST ,_____________O____x________, EAST 0 | 2PI // 6.2112
  //          ,            /|\   |        ,
  //           ,          / | \  |       ,
  //            ,        /  |  \ |      ,
  //              ,     /---x---\|   , '
  //                ' - , _ _ _ ,  '
  //                       SOUTH
  //                     270 | 3PI /2
  //

	if ((int)(ray - cube->rays) == 349)
		printf("Start\n");
	while (!hit)
	{
		ray->distance_y = distance_y(ray->y, ray->direction.y, ray->is_north);
		ray->distance_x = distance_x(ray->x, ray->direction.x, ray->is_east);
		if ((int)(ray - cube->rays) == 349) {
			printf("\tRay[%f %f] Updated Distances: [%f %f]\n",
				ray->y,
				ray->x,
				ray->distance_y,
				ray->distance_x
			);
		}
		increment_ray_length(ray, get_y_step(ray->distance_y, ray->angle),
			get_x_step(ray->distance_x, ray->angle));
		if ((int)(ray - cube->rays) == 349) {
			printf("After increment [%f %f]\n",
				ray->y,
				ray->x
			);
		}
		if (check_wall(ray->y, ray->x, cube))
		{
			wall_collision(ray);
			wall_point(ray);
			hit = 1;
		}
	}
}

void	raycasting(t_cube *cube, t_ray *rays)
{
	double	angle;
	double	delta_angle;
	int		pixel_column;

	angle = cube->player.angle - (HALF_FOV);
	pixel_column = 0;
	while (pixel_column < SCREEN_WIDTH)
	{
		castray(&rays[pixel_column], &cube->player, cube, angle);
		delta_angle = cube->player.angle - angle;
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

void	draw_ray(t_image *image, t_player *player, t_cube *cube, double angle)
{
	int		i;
	t_ray	ray;

	i = 1;
	castray(&ray, player, cube, angle);
	while (i <= (double)ray.length)
	{
		my_mlx_pixel_put(image, player->position.x + (i * cos(angle)),
			player->position.y + (i * sin(angle)), 0x0000ff00);
		i++;
	}
}
