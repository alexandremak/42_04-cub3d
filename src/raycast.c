/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:17:32 by amak              #+#    #+#             */
/*   Updated: 2024/04/07 19:58:00 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	wall_collision(t_ray *ray)
{
	if (ray->vert_wall)
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

static void	castray(t_ray *ray, t_player *player, t_file *file, float angle)
{
	int		stop;

	stop = 0;
	ray->wall_texture = NONE;
	ray->vert_wall = 0;
	ray->length = 0;
	ray->y = (int)player->position.y;
	ray->x = (int)player->position.x;
	ray->angle = angle;
	ray->direction.x = cos(angle);
	ray->direction.y = sin(angle);
	while (!stop)
	{
		ray->offY = offsety(ray->y, angle);
		ray->offX = offsetx(ray->x, angle);
		add_small_lenght(ray, calc_ydist(ray->offY, ray->angle), 
			calc_xdist(ray->offX, ray->angle));
		if (check_wall(ray->y, ray->x, file->map))
		{
			wall_collision(ray);
			stop = 1;
		}
	}
}

void	draw_ray(t_image *image, t_player *player, t_file *file, float angle)
{
	int		i;
	t_ray	ray;

	i = 1;
	castray(&ray, player, file, angle);
	while (i <= (int)ray.length)
	{
		my_mlx_pixel_put(image, 
			player->position.x + (i * cos(angle)), 
			player->position.y + (i * sin(angle)), 0x0000ff00);
		i++;
	}
}
