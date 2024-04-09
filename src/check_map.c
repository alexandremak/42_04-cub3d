/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:40:17 by amak              #+#    #+#             */
/*   Updated: 2024/04/09 21:05:21 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	check_invalid_chr(t_cube *file, char **map)
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

void	check_map(t_cube *file, char **map)
{
	check_invalid_chr(file, map);
	check_player(file, map);
	check_perimeter(file, map);
	check_inside(file, map);
}
