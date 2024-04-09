/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:05:31 by amak              #+#    #+#             */
/*   Updated: 2024/04/09 19:06:42 by ftroiter         ###   ########.fr       */
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

	pixel_address = image_data->addr + (y * image_data->line_length + x * 
			(image_data->bits_per_pixel / 8));
	pixel_location = (unsigned int *)pixel_address;
	*pixel_location = color;
}

void	init_mlx(t_cube *file)
{
	file->graphic.mlx = mlx_init();
	load_textures(file);
	file->graphic.win = mlx_new_window(file->graphic.mlx, 
			SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d - 3D Map");
	render_scene(file);
}


int	key_press(int keycode, t_cube *file)
{
	if (keycode == ESC)
		exit_game(file);
	else
	{
		if (keycode == W || keycode == S || keycode == A || keycode == D)
			move(&file->player, keycode, file->map);
		else if (keycode == LA)
		{
			file->player.angle -= (PI / PIDIVUNITS);
			if (file->player.angle < 0)
				file->player.angle += (2 * PI);
			file->player.direction.x = cos(file->player.angle);
			file->player.direction.y = sin(file->player.angle);
		}
		else if (keycode == RA)
		{
			file->player.angle += (PI / PIDIVUNITS);
			if (file->player.angle > (2 * PI))
				file->player.angle -= (2 * PI);
			file->player.direction.x = cos(file->player.angle);
			file->player.direction.y = sin(file->player.angle);
		}
		else if (keycode == M)
			file->show_minimap = !file->show_minimap;
		render_scene(file);
	}
	return (0);
}

