/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:43:54 by amak              #+#    #+#             */
/*   Updated: 2024/03/09 19:13:13 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	load_file(char **mtrx, int fd, int count_line)
{
	char	*line;

	line = get_next_line(fd);
	printf("line: %s", line);
	if (line)
		load_file(mtrx, fd, count_line + 1);
	else if (count_line > 0)
		mtrx = malloc(sizeof(char *) * (count_line + 1));
	if (mtrx)
		mtrx[count_line] = line;
}

static void	extract_ceiling(t_file *file, char **split)
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
	file->ceiling_rgb[0] = ft_atoi(numbers[0]);
	file->ceiling_rgb[1] = ft_atoi(numbers[1]);
	file->ceiling_rgb[2] = ft_atoi(numbers[2]);
	free_mtrx(numbers);
}
	
	
static void	extract_floor(t_file *file, char **split)
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
	file->floor_rgb[0] = ft_atoi(numbers[0]);
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
	else if (ft_strcmp(split[0], "C") == 0)
		extract_ceiling(file, split);
	else if (ft_strcmp(split[0], "F") == 0)
		extract_floor(file, split);
}

static void	load_values(t_file *file, char **content)
{
	char	*line;
	char	**split_line;

	while (content && *content)
	{
		ft_putspace(*content);
		line = ft_strtrim(*content, " \t\v\f\r\n");
		if (line && *line) 
		{
			split_line = ft_split(line, ' ');
			if (split_line && split_line[0])
				load_data(file, split_line);
			free_mtrx(split_line);
			free (line);
		}
		content++;
	}
}

void	read_content(t_file *file)
{
	char	**content;
	int		i;

	content = NULL;
	i = -1;
	printf("FD = %d\n", file->fd);
	load_file(content, file->fd, 0);
	printf("\nOLA! %s \n", content[0]);
	while (content[++i])
	{
		printf("content[%d]: %s", i, content[i]);
	}
	if (!content)
		exit_game(W_CONTENT, file);
	load_values(file, content);
	free_mtrx(content);
}
