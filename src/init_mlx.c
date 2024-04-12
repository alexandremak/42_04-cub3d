/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:05:31 by amak              #+#    #+#             */
/*   Updated: 2024/04/11 16:38:19 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel_to_image(t_image *image_data, int x, int y, int color)
{
	char			*pixel_address;
	unsigned int	*pixel_location;

	pixel_address = image_data->addr + (y * image_data->line_length + x
			* (image_data->bits_per_pixel / 8));
	pixel_location = (unsigned int *)pixel_address;
	*pixel_location = color;
}

void	init_mlx(t_cube *cube)
{
	cube->graphic.mlx = mlx_init();
	load_textures(cube);
	cube->graphic.win = mlx_new_window(cube->graphic.mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Cub3d - 3D Map");
	cube->rays = (t_ray *)malloc(sizeof(t_ray) * SCREEN_WIDTH);
	if (!cube->rays)
		exit_error("Couldn't allocate for rays", cube);
	cube->redline = 349;
	render_scene(cube);
}
