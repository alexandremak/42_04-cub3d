/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:04:36 by facu              #+#    #+#             */
/*   Updated: 2024/04/11 16:36:34 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	is_valid_char(char c)
{
	return (ft_strchr("10NSEW", c) != NULL);
}

static int	is_valid_cell(char **map, int i, int j)
{
	if (map[i][j] && ft_strchr("0NSEW", map[i][j]))
	{
		if (is_valid_char(map[i - 1][j]) && is_valid_char(map[i + 1][j])
			&& is_valid_char(map[i][j - 1]) && is_valid_char(map[i][j + 1])
			&& is_valid_char(map[i - 1][j - 1]) && is_valid_char(map[i - 1][j
				+ 1]) && is_valid_char(map[i + 1][j + 1]) && is_valid_char(map[i
				+ 1][j - 1]))
			return (1);
		else
			return (0);
	}
	return (1);
}

void	check_inside(t_cube *cube, char **map)
{
	int	i;
	int	j;

	i = 1;
	while (i < cube->rows - 1)
	{
		j = 1;
		while (j < cube->columns)
		{
			if (!is_valid_cell(map, i, j))
				exit_error("Invalid map perimeter", cube);
			j++;
		}
		i++;
	}
}
