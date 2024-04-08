/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:46:48 by amak              #+#    #+#             */
/*   Updated: 2024/04/08 00:08:56 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	free_str_arr(char **arr)
{
	int	i;

	i = 0;
	if (*arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

static void	free_file(t_file *file)
{
	if (file->filepath)
		free(file->filepath);
	int i = 0;
	while (i < 4)
	{
		if (file->texture_paths[i])
			free(file->texture_paths[i]);
		i++;
	}
	if (file->content)
		free_str_arr(file->content);
	if (file->map)
		free_str_arr(file->map);
}

void	free_all(t_file *file)
{
	free_file(file);
}
