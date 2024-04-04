/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:05:31 by amak              #+#    #+#             */
/*   Updated: 2024/04/02 20:35:00 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_mlx(t_file *file)
{
	file->graphic.mlx = mlx_init();
	file->graphic.win = mlx_new_window(file->graphic.mlx, 
			(file->collums - 1) * PX, file->rows * PX, "Cub3d - 2D Map");
	file->graphic.image.img = mlx_new_image(file->graphic.mlx, 
			(file->collums - 1) * PX, file->rows * PX);
	file->graphic.image.addr = mlx_get_data_addr(file->graphic.image.img,
		 &(file->graphic.image.bits_per_pixel), &file->graphic.image.line_length,	
		 &file->graphic.image.endian);
	draw_map(file, &file->graphic);
}

int	key_press(int keycode, t_file *file)
{
	if (keycode == ESC)
		exit_game(file);
	else
	{
		if (keycode == W)
		{
			move(&file->player, 'W', file->map);
			printf("W\n");
		}
		else if (keycode == S)
		{
			move(&file->player, 'S', file->map);
			printf("S\n");
		}
		else if (keycode == A)
		{
			file->player.angle -= (PI / DIVUNITS);
			if (file->player.angle < 0)
				file->player.angle += (2 * PI);
			file->player.direction.x = cos(file->player.angle);
			file->player.direction.y = sin(file->player.angle);
		}
		else if (keycode == D)
		{
			file->player.angle += (PI / DIVUNITS);
			if (file->player.angle > (2 * PI))
				file->player.angle -= (2 * PI);
			file->player.direction.x = cos(file->player.angle);
			file->player.direction.y = sin(file->player.angle);
		}
		draw_map(file, &file->graphic);
	}
	return (0);
}
