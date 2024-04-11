/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:52:51 by ftroiter          #+#    #+#             */
/*   Updated: 2024/04/11 16:39:17 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	max_columns(char **content)
{
	int	res;

	res = 0;
	if (!content)
		return (res);
	while (*content)
	{
		if ((int)ft_strlen(*content) > res)
			res = (int)ft_strlen(*content) + 1;
		content++;
	}
	return (res);
}

static int	max_rows(t_cube *cube, char **content)
{
	int	res;

	res = 0;
	if (!content)
		return (res);
	while (*content)
	{
		if (ft_noprintchar(*content))
			exit_error("Map content has to be the last", cube);
		res++;
		content++;
	}
	return (res);
}

static void	extract_map(t_cube *cube, char **content)
{
	int	i;
	int	j;

	i = 0;
	cube->map = ft_calloc(cube->rows + 1, sizeof(char *));
	while (i < cube->rows)
	{
		cube->map[i] = ft_calloc(cube->columns + 1, sizeof(char));
		j = 0;
		while (content[i][j])
		{
			cube->map[i][j] = content[i][j];
			j++;
		}
		i++;
	}
}

void	parse_map(t_cube *cube, char **content)
{
	cube->rows = max_rows(cube, content);
	cube->columns = max_columns(content);
	extract_map(cube, content);
}
