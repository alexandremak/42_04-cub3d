/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:43:54 by amak              #+#    #+#             */
/*   Updated: 2024/03/06 23:45:02 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	load_file(t_file *file, int count_line)
{
	char	*line;

	line = get_next_line(file->fd);
	if (line)
		load_file(file, count_line + 1);
	else if (count_line > 0)
		file->map = malloc(sizeof(char *) * (count_line + 1));
	if (file->map)
		file->map[count_line] = line;
}

static void	load_texture(t_file *file, char **split)
{
	if (ft_strcmp(split[0], "NO") == 0)
		file->no = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "SO") == 0)
		file->so = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "WE") == 0)
		file->we = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "EA") == 0)
		file->ea = ft_strdup(split[1]);
}

static void	load_values(t_file *file, char **map)
{
	char	*line;
	char	**split_line;

	while (map && *map)
	{
		ft_putspace(*map);
		line = ft_trimstr(*map);
		if (line)
		{
			split_line = ft_split(*map, ' ');
			if (split_line && split_line[0])
			{
				load_texture(file, split_line);
				free_mtrx(split_line);
			}
			free (line);
		}
		map++;
	}
}

void	read_content(t_file *file)
{
	load_file(file, 0);
	load_values(file, file->map);
}
