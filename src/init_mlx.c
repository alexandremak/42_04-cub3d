/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:05:31 by amak              #+#    #+#             */
/*   Updated: 2024/03/28 22:48:09 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_mlx(t_file *file)
{	
	int s;

    file->graphic.mlx = mlx_init();
    file->graphic.win = mlx_new_window(file->graphic.mlx, (file->collums - 2) * PX,
        file->rows * PX, "Cub3d - 2D Map");
	file->player.img = mlx_xpm_file_to_image(file->graphic.mlx, 
		"./imgs/player.xpm", &s, &s);
	draw_player(file, &file->graphic);
}
int	key_press(int keycode, t_file *file)
{
	if (keycode == ESC)
		exit_game(file);
	else
	{
		if (keycode == W)
		{
			if(!check_wall(file->player.position.y - PACE, file->player.position.x,
				file->map))
				file->player.position.y -= PACE;
		}
		else if (keycode == S)
		{
			if(!check_wall(file->player.position.y + PACE, file->player.position.x,
				file->map))
				file->player.position.y += PACE;
		}
		else if (keycode == A)
		{
			if(!check_wall(file->player.position.y, file->player.position.x - PACE,
				file->map))
				file->player.position.x -= PACE;
		}
		else if (keycode == D)
		{
			if(!check_wall(file->player.position.y, file->player.position.x + PACE,
				file->map))
				file->player.position.x += PACE;
		}
		draw_player(file, &file->graphic);
	}
	return (0);
}
