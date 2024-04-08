/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:25:49 by amak              #+#    #+#             */
/*   Updated: 2024/04/04 21:55:44 by ftroiter         ###   ########.fr       */
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

static int	max_rows(t_file *file, char **content)
{
	int	res;

	res = 0;
	if (!content)
		return (res);
	while (*content)
	{
		if (ft_noprintchar(*content))
			exit_error("Map content has to be the last", file);
		res++;
		content++;
	}
	return (res);
}

static void	extract_map(t_file *file, char **content)
{
	int	i;
	int	j;

	i = 0;
	file->map = ft_calloc(file->rows + 1, sizeof(char *));
	while (i < file->rows)
	{
		file->map[i] = ft_calloc(file->columns + 1, sizeof(char));
		j = 0;
		while (content[i][j])
		{
			file->map[i][j] = content[i][j];
			j++;
		}
		i++;
	}
}

void	get_map(t_file *file, char **content)
{
	file->rows = max_rows(file, content);
	file->columns = max_columns(content);
	extract_map(file, content);
}
