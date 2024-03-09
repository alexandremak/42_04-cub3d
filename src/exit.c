/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:41:46 by amak              #+#    #+#             */
/*   Updated: 2024/03/09 18:29:48 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	exit_game(t_exit_code exit_code, t_file *file)
{
	free_all(file);
	if (file->fd > -1)
		close(file->fd);
	if (exit_code == NORMAL)
		exit(0);
	printf("Error\n");
	if (exit_code == ARGC_ERROR)
		printf("Invalid number of arguments!\n");
	if (exit_code == BLANK_FPATH)
		printf("Inserted blank filepath or filename!\n");
	if (exit_code == EXT_ERROR)
		printf("Scene description file with incorrect extension!\n");
	if (exit_code == NO_FILE)
		printf("Scene description file doesn't exist!\n");
	if (exit_code == W_CONTENT)
		printf("File with wrong or no content!\n");
	if (exit_code == NOALL_TEXTURES)
		printf("File content missing one or more texture path!\n");
	if (exit_code == RGB_IRANGE)
		printf("File with one or more invalid RGB colors range!\n");
	if (exit_code == MAP_NCLOSED)
		printf("File with a map thar is not closed/surrounded!\n");
	if (exit_code == INVALID_CONTENT)
		printf("File with an invalid content!\n");
	exit(1);
}
