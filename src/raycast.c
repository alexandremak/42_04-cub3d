/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:17:32 by amak              #+#    #+#             */
/*   Updated: 2024/04/07 20:08:09 by facu             ###   ########.fr       */
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
	int	hit;

	hit = 0;
	ray->length = 0;
	ray->y = (int)player->position.y;
	ray->x = (int)player->position.x;
	ray->angle = angle;
	ray->direction.x = cos(angle);
	ray->direction.y = sin(angle);
	printf("\n\n\n\n\n");
	while (!hit)
	{
		ray->distance_y = distance_y(ray->y, angle);
		ray->distance_x = distance_x(ray->x, angle);
		increment_ray_length(ray, get_y_step(ray->distance_y, ray->angle),
			get_x_step(ray->distance_x, ray->angle));
		if (check_wall(ray->y, ray->x, file->map))
		{
			wall_collision(ray);
			hit = 1;
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
		my_mlx_pixel_put(image, player->position.x + (i * cos(angle)),
			player->position.y + (i * sin(angle)), 0x0000ff00);
		i++;
	}
}
