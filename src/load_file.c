/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:43:54 by amak              #+#    #+#             */
/*   Updated: 2024/04/08 19:40:24 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	get_content(t_file *file, int fd, int count_line)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		get_content(file, fd, count_line + 1);
	else if (count_line > 0)
		file->content = malloc(sizeof(char *) * (count_line + 1));
	if (file->content)
		file->content[count_line] = line;
}

void	read_scene_file(t_file *file)
{
	get_content(file, file->fd, 0);
	if (!file->content)
		exit_error("Scene description file without content!", file);
	parse_values(file, file->content);
}
