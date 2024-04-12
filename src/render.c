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

static void	create_new_image(t_window *graphic)
{
	if (graphic->image.img != NULL)
		mlx_destroy_image(graphic->mlx, graphic->image.img);
	graphic->image.img = mlx_new_image(graphic->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	graphic->image.addr = mlx_get_data_addr(graphic->image.img,
			&(graphic->image.bits_per_pixel), &(graphic->image.line_length),
			&(graphic->image.endian));
}

void	render_scene(t_cube *cube)
{
	t_window	*graphic;

	// cube->rays = (t_ray *)malloc(sizeof(t_ray) * SCREEN_WIDTH);
	graphic = &cube->graphic;
	create_new_image(graphic);
	raycasting(cube, cube->rays);
	draw_floor_and_ceiling(cube);
	draw_walls(cube, cube->rays);
	if (cube->show_minimap)
		draw_minimap(cube, graphic);
	// free(cube->rays);
	for (int i = 0; i < SCREEN_HEIGHT; ++i) {
		my_mlx_pixel_put(&cube->graphic.image, cube->redline, i, 0xff0000);
	}
	mlx_put_image_to_window(graphic->mlx, graphic->win, graphic->image.img, 0,
		0);
}
