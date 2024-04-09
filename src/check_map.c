/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:40:17 by amak              #+#    #+#             */
/*   Updated: 2024/04/09 19:06:42 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	check_chr(t_cube *file, char **map)
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
				exit_error("Invalid characters on map", file);
			j++;
		}
		i++;
	}
}

static void	check_player(t_cube *file, char **map)
{
	int	i;
	int	j;
	int	player_found;

	i = 0;
	j = 0;
	player_found = 0;
	while (i < file->rows)
	{
		j = 0;
		while (j < file->columns)
		{
			if (map[i][j] && ft_strchr("NSEW", map[i][j]))
			{
				if (player_found)
					exit_error("Invalid player position", file);
				player_found = 1;
				extract_player_position(file, i, j, map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (!player_found)
		exit_error("Invalid player position", file);
}

static void	check_perimeter(t_cube *file, char **map)
{
	int	i;
	int	last_row;
	int	last_col;

	i = 0;
	last_row = file->rows - 1;
	last_col = file->columns - 1;
	while (i < file->columns)
	{
		if (map[0][i] && ft_strchr("0NSEW", map[0][i]))
			exit_error("Invalid map perimeter", file);
		if (map[last_row][i] && ft_strchr("0NSEW", map[last_row][i]))
			exit_error("Invalid map perimeter", file);
		if (i > 0 && i < last_row)
		{
			if (map[i][0] && ft_strchr("0NSEW", map[i][0]))
				exit_error("Invalid map perimeter", file);
			if (map[i][last_col] && ft_strchr("0NSEW", map[i][last_col]))
				exit_error("Invalid map perimeter", file);
		}
		i++;
	}
}
static int	is_invalid_cell(t_cube *file, char **map, int i, int j)
{
	if (map[i][j] && ft_strchr("0NSEW", map[i][j]))
	{
		if (!ft_strchr("10NSEW", map[i - 1][j]) || 
			!ft_strchr("10NSEW", map[i + 1][j]) ||
			!ft_strchr("10NSEW", map[i][j - 1]) ||
			!ft_strchr("10NSEW", map[i][j + 1]) ||
			!ft_strchr("10NSEW", map[i - 1][j - 1]) ||
			!ft_strchr("10NSEW", map[i - 1][j + 1]) ||
			!ft_strchr("10NSEW", map[i + 1][j + 1]) ||
			!ft_strchr("10NSEW", map[i + 1][j - 1]))
			return (1);
	}
	return (0);
}

static void	check_inside(t_cube *file, char **map)
{
	int	i = 1;
	int	j;

	while (i < file->rows - 1)
	{
		j = 1;
		while (j < file->columns)
		{
			if (is_invalid_cell(file, map, i, j))
				exit_error("Invalid map perimeter", file);
			j++;
		}
		i++;
	}
}

void	check_map(t_cube *file, char **map)
{
	check_chr(file, map);
	check_player(file, map);
	check_perimeter(file, map);
	check_inside(file, map);
}
