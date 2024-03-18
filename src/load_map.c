/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:25:49 by amak              #+#    #+#             */
/*   Updated: 2024/03/18 23:23:09 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	max_row(char **mtrx)
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

static int	max_lines(char **mtrx)
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

void alocate_map(t_file *file, char **mtrx, int y, int x)
{
	int	i;
	int	j;
	
	i = 0;
	file->map = (char **)malloc((y + 1) * sizeof(char *));
	while(i < y)
	{
		file->map[i] = ft_calloc(x, sizeof(char));
		j = 0;
		while (mtrx[i][j])
		{
			file->map[i][j] = mtrx[i][j];
			printf("%c", file->map[i][j]);
			j++;
		}
		i++;
	}
	printf("\n>>>>>See map: \n");
	while(file->map && *file->map)
	{
		printf("%s", *file->map);
		file->map++;
	}
}

void	load_map(t_file *file, char **mtrx)
{
	alocate_map(file, mtrx, max_lines(mtrx), max_row(mtrx));
	printf("\n>>>>>See map: \n");
	while(file->map && *file->map)
	{
		printf("%s", *file->map);
		file->map++;
	}
}
