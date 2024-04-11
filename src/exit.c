/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:41:46 by amak              #+#    #+#             */
/*   Updated: 2024/04/11 16:38:19 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	exit_error(char *message, t_cube *cube)
{
	free_all(cube);
	if (cube->fd > -1)
		close(cube->fd);
	if (message)
		ft_print_error(1, message);
	exit(1);
}

void	exit_game(t_cube *cube)
{
	free_all(cube);
	if (cube->fd > -1)
		close(cube->fd);
	if (cube->graphic.win)
		mlx_destroy_window(cube->graphic.mlx, cube->graphic.win);
	if (cube->graphic.image.img)
		mlx_destroy_image(cube->graphic.mlx, cube->graphic.image.img);
	if (cube->graphic.mlx)
	{
		mlx_destroy_display(cube->graphic.mlx);
		free(cube->graphic.mlx);
	}
	exit(0);
}
