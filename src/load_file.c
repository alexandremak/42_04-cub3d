/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:43:54 by amak              #+#    #+#             */
/*   Updated: 2024/04/11 16:38:19 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	get_content(t_cube *cube, int fd, int count_line)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		get_content(cube, fd, count_line + 1);
	else if (count_line > 0)
		cube->content = malloc(sizeof(char *) * (count_line + 1));
	if (cube->content)
		cube->content[count_line] = line;
}

void	read_scene_file(t_cube *cube)
{
	get_content(cube, cube->fd, 0);
	if (!cube->content)
		exit_error("Empty scene description file", cube);
	parse_values(cube, cube->content);
}
