/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:04:29 by ftroiter          #+#    #+#             */
/*   Updated: 2024/04/09 16:35:03 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void create_new_image(t_window *graphic) {
	if (graphic->image.img != NULL)
		mlx_destroy_image(graphic->mlx, graphic->image.img);
	graphic->image.img = mlx_new_image(graphic->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	graphic->image.addr = mlx_get_data_addr(graphic->image.img, 
			&(graphic->image.bits_per_pixel), 
			&(graphic->image.line_length), 
			&(graphic->image.endian));
}

void	render_scene(t_cube *file)
{
	t_window	*graphic;
	t_ray		*rays; // TODO: move to file struct

	rays = (t_ray *)malloc(sizeof(t_ray) * SCREEN_WIDTH);
	graphic = &file->graphic;
	create_new_image(graphic);
	raycasting(file, rays);
	draw_floor_and_ceiling(file);
	draw_walls(file, rays);
	if (file->show_minimap)
		draw_minimap(file, graphic);
	free(rays);
	mlx_put_image_to_window(graphic->mlx, graphic->win, graphic->image.img, 0, 0);
}