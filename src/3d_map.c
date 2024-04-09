/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:49:01 by ftroiter          #+#    #+#             */
/*   Updated: 2024/04/09 19:06:42 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	draw_wall_column(t_cube *file, t_ray ray, int start_point[2], int end_y, int texture_offset, int wall_height)
{
	int		color;
	int		y;

	y = start_point[1];
	while (y < end_y)
	{
		color = get_texture_color(file, y, texture_offset, ray, wall_height);
		my_mlx_pixel_put(&file->graphic.image, start_point[0], y, color);
		y++;
	}
}

void	draw_walls(t_cube *file, t_ray *rays)
{
	int		ray;
	int		start_point[2];
	int		end_y;
	int		texture_offset;
	int		wall_height;

	ray = 0;
	while (ray < SCREEN_WIDTH)
	{
		wall_height = ((PX / rays[ray].length) * PLANE_DIST);
		start_point[X] = ray;
		start_point[Y] = floor(SCREEN_HEIGHT / 2) - (wall_height / 2);
		if (start_point[Y] < 0)
			start_point[Y] = 0;
		end_y = floor(SCREEN_HEIGHT / 2) + (wall_height / 2);
		if (end_y >= SCREEN_HEIGHT)
			end_y = SCREEN_HEIGHT - 1;
		texture_offset = rays[ray].wall_hit;
		draw_wall_column(file, rays[ray], start_point, end_y, texture_offset, wall_height);
		ray++;
	}	
}

int	rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	color_fill(t_cube *file, int start_y, int end_y, int color)
{
	int x = 0, y = start_y;

	while (y < end_y)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&file->graphic.image, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_floor_and_ceiling(t_cube *cube)
{
	int color;

	color = rgb_to_int(cube->ceiling_rgb[0], cube->ceiling_rgb[1], cube->ceiling_rgb[2]);
	color_fill(cube, 0, SCREEN_HEIGHT / 2, color);
	color = rgb_to_int(cube->floor_rgb[0], cube->floor_rgb[1], cube->floor_rgb[2]);
	color_fill(cube, SCREEN_HEIGHT / 2, SCREEN_HEIGHT, color);
}