/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:41:46 by amak              #+#    #+#             */
/*   Updated: 2024/03/13 21:22:34 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	exit_game(t_exit_code exit_code, char *message, t_file *file)
{
	free_all(file);
	if (file->fd > -1)
		close(file->fd);
	if (exit_code == NORMAL)
		exit(0);
	printf("Error\n");
	printf("%s\n", message);
	exit(1);
}
