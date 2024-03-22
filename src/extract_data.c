/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:00:21 by amak              #+#    #+#             */
/*   Updated: 2024/03/22 01:32:41 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	extract_txtr(t_file *file, char **texture, char *pathstr)
{
	int	fd;

	fd = open(pathstr, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		exit_game(ERROR, \
		"Scene description file with a wall texture file not found!", file);
	}
	if (texture && *texture)
		exit_game(ERROR, \
		"Scene description file with duplicate wall texture identifier!", file);
	*texture = ft_strdup(pathstr);
	close(fd);
}

static void	extract_rgb(t_file *file, int *rgb, char *splited)
{
	char	**numbers;
	int		i;

	i = -1;
	if (rgb[3])
		exit_game(ERROR, 
			"Scene description file with duplicate RGB values!", file);
	if (!splited)
		exit_game(ERROR, "Scene description file with no RGB values!", file);
	numbers = ft_split(splited, ',');
	while (*numbers && numbers[++i])
	{
		if (ft_strlen(numbers[i]) > 4)
		{
			free_mtrx(numbers);
			exit_game(ERROR, \
			"Scene description file with invalid RGB values!", file);
		}
		rgb[i] = ft_atoi(numbers[i]);
	}
	free_mtrx(numbers);
	if (i < 3)
		exit_game(ERROR, 
			"Scene description file with insuficient RGB values!", file);
	rgb[3] = 1;
}

void	extract_data(t_file *file, char **splited)
{
	if (ft_strcmp(splited[0], "NO") == 0)
		extract_txtr(file, &file->no, splited[1]);
	else if (ft_strcmp(splited[0], "SO") == 0)
		extract_txtr(file, &file->so, splited[1]);
	else if (ft_strcmp(splited[0], "WE") == 0)
		extract_txtr(file, &file->we, splited[1]);
	else if (ft_strcmp(splited[0], "EA") == 0)
		extract_txtr(file, &file->ea, splited[1]);
	else if (ft_strcmp(splited[0], "C") == 0)
		extract_rgb(file, file->ceiling_rgb, splited[1]);
	else if (ft_strcmp(splited[0], "F") == 0)
		extract_rgb(file, file->floor_rgb, splited[1]);
}
