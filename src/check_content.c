/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:38:34 by amak              #+#    #+#             */
/*   Updated: 2024/03/21 00:10:04 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void check_rgb(t_file *file, int *rgb_values)
{
	int	i;

	i = 0;
	if (rgb_values[3] == 0)
		exit_game(ERROR, "Scene description file with incomplete rgb values!", file);
	while (i < 3)
	{
		if (rgb_values[i] < 0 || rgb_values[i] > 255)
			exit_game(ERROR, "Scene description file with wrong rgb values!", file);
		i++;
	}
}

static void	check_map_chr(t_file *file, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < file->rows)
	{
		j = 0;
		while(j < file->collums)
		{
			if (!ft_strchr(" 01NSEW\n\0", map[i][j]))
				exit_game(ERROR, "Map with incorrect characters!", file);
			j++;
		}
		i++;
	}
}

static void	check_map_player(t_file *file, char **map)
{
	int	i;
	int	j;
	int	flag_player;

	i = 0;
	flag_player = 0;
	while (i < file->rows)
	{
		j = 0;
		while(j < file->collums)
		{
			if (map[i][j] && ft_strchr("NSEW", map[i][j]))
			{
				if (flag_player == 0)
					flag_player = 1;
				else
					exit_game(ERROR, "Map with more than one player position!", file);
			}		
			j++;
		}
		i++;
	}
	if (flag_player == 0)
		exit_game(ERROR, "Map with no player position!", file);
}

static void	check_map_wall(t_file *file, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < file->rows)
	{
		j = 0;
		while(j < file->collums)
		{
			printf("x = %d | y = %d | char: %c | str: %s\n", i, j, map[i][j], ft_strchr("0NSEW", map[i][j]));
			if ((i == 0 || i == (file->rows - 1)) && map[i][j] && ft_strchr("0NSEW", map[i][j]))
				exit_game(ERROR, "Map not closed/surrounded by walls!", file);

			else if (map[i][j] && ft_strchr("0NSEW", map[i][j]))
			{
				printf("<<<< AQUI! %c\n", map[i][j - 1]);
				if (!ft_strchr("10NSEW", map[i - 1][j]) || 
					!ft_strchr("10NSEW", map[i + 1][j]) ||
					!ft_strchr("10NSEW", map[i][j - 1]) ||
					!ft_strchr("10NSEW", map[i][j + 1]))
					exit_game(ERROR, "Map not closed/surrounded by walls!", file);
			}		
			j++;
		}
		i++;
	}
}

void	check_content(t_file *file)
{
	if (!file->no || !file->so || !file->we || !file->ea)
		exit_game(ERROR, "Scene description file with incomplete textures!", file);
	check_rgb(file, file->floor_rgb);
	check_rgb(file, file->ceiling_rgb);
	check_map_chr(file, file->map);
	check_map_player(file, file->map);
	check_map_wall(file, file->map);
	printf("\nMap OK!\n");
}
