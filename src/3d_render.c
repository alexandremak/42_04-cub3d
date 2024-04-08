/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:04:29 by ftroiter          #+#    #+#             */
/*   Updated: 2024/04/08 17:06:45 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	draw_wall(t_file *file, t_ray ray, int start_point[2], int end_y, int offset_x, int wall_height)
{
	int		color;
	int		y;

	y = start_point[1];
	while (y < end_y)
	{
		if (y >= 0 && y <= SCREEN_HEIGHT)
		{
			color = get_texture_color(file, y, offset_x, ray, wall_height);
			my_mlx_pixel_put(&file->graphic.image, start_point[0], y, color);
		}
		y++;
	}
}

void	draw_walls(t_file *file, t_ray *rays)
{
	int		ray;
	int		start_point[2];
	int		end_y;
	int		offset_x;
	int		wall_height;

	ray = 0;
	while (ray < SCREEN_WIDTH)
	{
		wall_height = ((PX / rays[ray].length) * PLANE_DIST);
		start_point[0] = ray;
		start_point[1] = floor(SCREEN_HEIGHT / 2) - (wall_height / 2);
		if (start_point[1] < 0)
			start_point[1] = 0;
		end_y = floor(SCREEN_HEIGHT / 2) + (wall_height / 2);
		if (end_y >= SCREEN_HEIGHT)
			end_y = SCREEN_HEIGHT - 1;
		offset_x = rays[ray].wall_hit;
		draw_wall(file, rays[ray], start_point, end_y, offset_x, wall_height);
		ray++;
	}	
}

void	render_cicle(t_file *file)
{
	t_window	*graphic;
	t_ray		*rays; // TODO: move to file struct

	rays = (t_ray *)malloc(sizeof(t_ray) * SCREEN_WIDTH);
	graphic = &file->graphic;
	if (graphic->image.img != NULL)
		mlx_destroy_image(graphic->mlx, graphic->image.img);
	graphic->image.img = mlx_new_image(graphic->mlx, 
			SCREEN_WIDTH, SCREEN_HEIGHT);
	graphic->image.addr = mlx_get_data_addr(graphic->image.img, 
			&(graphic->image.bits_per_pixel), 
			&graphic->image.line_length, 
			&graphic->image.endian);
	raycasting(file, rays);
	draw_walls(file, rays);
	free(rays);
	mlx_put_image_to_window(graphic->mlx, graphic->win, graphic->image.img, 0, 0);
}
