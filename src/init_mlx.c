/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:05:31 by amak              #+#    #+#             */
/*   Updated: 2024/04/07 19:55:25 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_mlx(t_file *file)
{
	file->graphic.mlx = mlx_init();
	file->graphic.win = mlx_new_window(file->graphic.mlx, 
			(file->columns - 1) * PX, file->rows * PX, "Cub3d - 2D Map");
	file->graphic.image.img = mlx_new_image(file->graphic.mlx, 
			(file->columns - 1) * PX, file->rows * PX);
	file->graphic.image.addr = mlx_get_data_addr(file->graphic.image.img, 
			&(file->graphic.image.bits_per_pixel), 
			&file->graphic.image.line_length, 
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
			move(&file->player, 'W', file->map);
		else if (keycode == S)
			move(&file->player, 'S', file->map);
		else if (keycode == A)

			move(&file->player, 'A', file->map);
		else if (keycode == D)
			move(&file->player, 'D', file->map);
		else if (keycode == LA)
		{
			file->player.angle -= (PI / DIVUNITS);
			if (file->player.angle < 0)
				file->player.angle += (2 * PI);
			file->player.direction.x = cos(file->player.angle);
			file->player.direction.y = sin(file->player.angle);
		}
		else if (keycode == RA)
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
