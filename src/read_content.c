/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:43:54 by amak              #+#    #+#             */
/*   Updated: 2024/03/09 00:28:36 by amak             ###   ########.fr       */
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
static void extract_nbr(t_file *file, char** split)
{
	char **numbers;
	int i;

	i = -1;
	numbers = ft_split(split[1], ',');
	while (*numbers && numbers[++i])
		if (ft_strlen(numbers[i]) > 3)
			{
				free(numbers);
				exit_game(W_CONTENT, file);
			}
	if (ft_strcmp(split[0], "C") == 0)
	{
		file->ceiling.red = ft_atoi(numbers[0]);
		file->ceiling.green = ft_atoi(numbers[1]);
		file->ceiling.blue = ft_atoi(numbers[2]);
	}
	else
	{
		file->floor.red = ft_atoi(numbers[0]);
		file->floor.green = ft_atoi(numbers[1]);
		file->floor.blue = ft_atoi(numbers[2]);
	}
	free(numbers);
}

static void	load_data(t_file *file, char **split)
{
	if (ft_strcmp(split[0], "NO") == 0)
		file->no = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "SO") == 0)
		file->so = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "WE") == 0)
		file->we = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "EA") == 0)
		file->ea = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "F") == 0 || ft_strcmp(split[0], "C") == 0)
		extract_nbr(file, split);
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
				load_data(file, split_line);
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
