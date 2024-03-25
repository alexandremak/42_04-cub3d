/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:05:31 by amak              #+#    #+#             */
/*   Updated: 2024/03/25 22:40:19 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_mlx(t_file *file)
{
    file->graphic.mlx = mlx_init();
    file->graphic.win = mlx_new_window(file->graphic.mlx, file->collums * PX, \
        file->rows * PX, "Cub3d - 2D Map");
}
int	key_press(int keycode, t_file *file)
{
	if (keycode == ESC)
		exit_game(file);
	// if (keycode == W)
	// {
	// }
	// if (keycode == S)
	// {
	// }
	// if (keycode == A)
	// {
	// }
	// if (keycode == D)
	// {
	// }
	return (0);
}
