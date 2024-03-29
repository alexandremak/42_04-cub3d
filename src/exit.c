/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:41:46 by amak              #+#    #+#             */
/*   Updated: 2024/03/29 13:47:39 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	exit_error(char *message, t_file *file)
{
	free_all(file);
	if (file->fd > -1)
		close(file->fd);
	printf("Error\n");
	printf("%s\n\n", message);
	exit(1);
}

void	exit_game(t_file *file)
{
	free_all(file);
	if (file->fd > -1)
		close(file->fd);
	if (file->graphic.win)
		mlx_destroy_window(file->graphic.mlx, file->graphic.win);
	if (file->graphic.mlx)
	{
		mlx_destroy_display(file->graphic.mlx);
		free(file->graphic.mlx);
	}
	exit(0);
}
