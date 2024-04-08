/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:05:31 by amak              #+#    #+#             */
/*   Updated: 2024/04/08 17:24:31 by ftroiter         ###   ########.fr       */
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

void	init_mlx(t_file *file)
{
	file->graphic.mlx = mlx_init();
/*	render 2d map

	file->graphic.win = mlx_new_window(file->graphic.mlx, 
			(file->columns - 1) * PX, file->rows * PX, "Cub3d - 2D Map");
			
	file->graphic.image.img = mlx_new_image(file->graphic.mlx, 
			(file->columns - 1) * PX, file->rows * PX); */
	load_textures(file);
	file->graphic.win = mlx_new_window(file->graphic.mlx, 
			SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d - 3D Map");
	render_cicle(file);
}


int	key_press(int keycode, t_file *file)
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
		render_cicle(file);
	}
	return (0);
}
