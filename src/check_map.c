/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:40:17 by amak              #+#    #+#             */
/*   Updated: 2024/04/11 16:35:52 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	check_invalid_chr(t_cube *cube, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cube->rows)
	{
		j = 0;
		while (j < cube->columns)
		{
			if (!ft_strchr(" 01NSEW\n\0", map[i][j]))
				exit_error("Invalid characters on map", cube);
			j++;
		}
		i++;
	}
}

static void	check_player(t_cube *cube, char **map)
{
	int	i;
	int	j;
	int	player_found;

	i = 0;
	j = 0;
	player_found = 0;
	while (i < cube->rows)
	{
		j = 0;
		while (j < cube->columns)
		{
			if (map[i][j] && ft_strchr("NSEW", map[i][j]))
			{
				if (player_found)
					exit_error("Invalid player position", cube);
				player_found = 1;
				extract_player_position(cube, i, j, map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (!player_found)
		exit_error("Invalid player position", cube);
}

static void	check_perimeter(t_cube *cube, char **map)
{
	int	i;
	int	last_row;
	int	last_col;

	i = 0;
	last_row = cube->rows - 1;
	last_col = cube->columns - 1;
	while (i < cube->columns)
	{
		if (map[0][i] && ft_strchr("0NSEW", map[0][i]))
			exit_error("Invalid map perimeter", cube);
		if (map[last_row][i] && ft_strchr("0NSEW", map[last_row][i]))
			exit_error("Invalid map perimeter", cube);
		if (i > 0 && i < last_row)
		{
			if (map[i][0] && ft_strchr("0NSEW", map[i][0]))
				exit_error("Invalid map perimeter", cube);
			if (map[i][last_col] && ft_strchr("0NSEW", map[i][last_col]))
				exit_error("Invalid map perimeter", cube);
		}
		i++;
	}
}

void	check_map(t_cube *cube, char **map)
{
	check_invalid_chr(cube, map);
	check_player(cube, map);
	check_perimeter(cube, map);
	check_inside(cube, map);
}
