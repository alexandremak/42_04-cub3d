/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:25:49 by amak              #+#    #+#             */
/*   Updated: 2024/03/22 00:55:20 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	max_collums(char **mtrx)
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

static void	extract_map(t_file *file, char **mtrx, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	file->map = ft_calloc(y + 1, sizeof(char *));
	while (i < y)
	{
		file->map[i] = ft_calloc(x + 1, sizeof(char));
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
	file->collums = max_collums(mtrx);
	extract_map(file, mtrx, max_rows(mtrx), max_collums(mtrx));
}
