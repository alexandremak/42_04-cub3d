/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:25:49 by amak              #+#    #+#             */
/*   Updated: 2024/04/04 19:58:15 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	max_columns(char **mtrx)
{
	int	res;

	res = 0;
	if (!mtrx)
		return (res);
	while (*mtrx)
	{
		if ((int)ft_strlen(*mtrx) > res)
			res = (int)ft_strlen(*mtrx) + 1;
		mtrx++;
	}
	return (res);
}

static int	max_rows(char **mtrx)
{
	int	res;

	res = 0;
	if (!mtrx)
		return (res);
	while (*mtrx)
	{
		res++;
		mtrx++;
	}
	return (res);
}

static void	extract_map(t_file *file, char **mtrx)
{
	int	i;
	int	j;

	i = 0;
	file->map = ft_calloc(file->rows + 1, sizeof(char *));
	while (i < file->rows)
	{
		file->map[i] = ft_calloc(file->columns + 1, sizeof(char));
		j = 0;
		while (mtrx[i][j])
		{
			file->map[i][j] = mtrx[i][j];
			j++;
		}
		i++;
	}
}

void	load_map(t_file *file, char **mtrx)
{
	file->rows = max_rows(mtrx);
	file->columns = max_columns(mtrx);
	extract_map(file, mtrx);
}
