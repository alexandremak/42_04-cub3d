/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:41:46 by amak              #+#    #+#             */
/*   Updated: 2024/04/09 19:06:42 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	exit_error(char *message, t_cube *file)
{
	free_all(file);
	if (file->fd > -1)
		close(file->fd);
	if (message)
		ft_print_error(1, message);
	exit(1);
}

void	exit_game(t_cube *file)
{
	free_all(file);
	if (file->fd > -1)
		close(file->fd);
	if (file->graphic.win)
		mlx_destroy_window(file->graphic.mlx, file->graphic.win);
	if (file->graphic.image.img)
		mlx_destroy_image(file->graphic.mlx, file->graphic.image.img);
	if (file->graphic.mlx)
	{
		mlx_destroy_display(file->graphic.mlx);
		free(file->graphic.mlx);
	}
	exit(0);
}
