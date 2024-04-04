/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:40:17 by amak              #+#    #+#             */
/*   Updated: 2024/04/04 21:10:59 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	check_chr(t_file *file, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < file->rows)
	{
		j = 0;
		while (j < file->columns)
		{
			if (!ft_strchr(" 01NSEW\n\0", map[i][j]))
				exit_error("Map with incorrect characters!", file);
			j++;
		}
		i++;
	}
}

static void	check_player(t_file *file, char **map)
{
	int	i;
	int	j;
	int	flag_player;

	i = 0;
	j = 0;
	flag_player = 0;
	while (i < file->rows)
	{
		j = 0;
		while (j < file->columns)
		{
			if (map[i][j] && ft_strchr("NSEW", map[i][j]))
			{
				if (flag_player == 1)
					exit_error("Map with more than a player position!", file);
				flag_player = 1;
				extract_player_position(file, i, j, map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (flag_player == 0)
		exit_error("Map with no player position!", file);
}

static void	check_perimeter(t_file *file, char **map)
{
	int	i;
	int	j;
	int	last_row;
	int	last_col;

	i = 1;
	j = 0;
	last_row = file->rows - 1;
	last_col = file->columns - 1;
	while (j < file->columns)
	{
		if (map[0][j] && ft_strchr("0NSEW", map[0][j]))
			exit_error("Map not closed/surrounded by walls!", file);
		if (map[last_row][j] && ft_strchr("0NSEW", map[last_row][j]))
			exit_error("Map not closed/surrounded by walls!", file);
		j++;
	}
	while (i <= last_row)
	{
		if (map[i][0] && ft_strchr("0NSEW", map[i][0]))
			exit_error("Map not closed/surrounded by walls!", file);
		if (map[i][last_col] && ft_strchr("0NSEW", map[i][last_col]))
			exit_error("Map not closed/surrounded by walls!", file);
		i++;
	}
}

static void	check_inside(t_file *file, char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < file->rows - 1)
	{
		j = 1;
		while (j < file->columns)
		{
			if (map[i][j] && ft_strchr("0NSEW", map[i][j]))
			{
				if (!ft_strchr("10NSEW", map[i - 1][j]) || 
					!ft_strchr("10NSEW", map[i + 1][j]) ||
					!ft_strchr("10NSEW", map[i][j - 1]) ||
					!ft_strchr("10NSEW", map[i][j + 1]))
					exit_error("Map not closed/surrounded by walls!", file);
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_file *file, char **map)
{
	check_chr(file, map);
	check_player(file, map);
	check_perimeter(file, map);
	check_inside(file, map);
}
