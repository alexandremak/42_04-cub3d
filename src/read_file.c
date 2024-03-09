/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:43:54 by amak              #+#    #+#             */
/*   Updated: 2024/03/09 17:21:50 by amak             ###   ########.fr       */
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

static void	extract_nbr(t_file *file, char **split)
{
	char	**numbers;
	int		i;

	i = -1;
	numbers = ft_split(split[1], ',');
	while (*numbers && numbers[++i])
	{
		if (ft_strlen(numbers[i]) > 4)
		{
			free_mtrx(numbers);
			exit_game(W_CONTENT, file);
		}
	}
	if (i < 3)
	{
		free_mtrx(numbers);
		exit_game(W_CONTENT, file);
	}
	if (ft_strcmp(split[0], "C") == 0)
	{
		file->ceiling_rgb[0] = ft_atoi(numbers[0]);
		file->ceiling_rgb[1] = ft_atoi(numbers[1]);
		file->ceiling_rgb[2] = ft_atoi(numbers[2]);
		free_mtrx(numbers);
		return;
	}
	file->floor_rgb[0]= ft_atoi(numbers[0]);
	file->floor_rgb[1] = ft_atoi(numbers[1]);
	file->floor_rgb[2] = ft_atoi(numbers[2]);
	free_mtrx(numbers);
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
		line = ft_strtrim(*map," \t\v\f\r\n");
		if (line && *line) 
		{
			split_line = ft_split(line, ' ');
			if (split_line && split_line[0])
				load_data(file, split_line);
			free_mtrx(split_line);
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
