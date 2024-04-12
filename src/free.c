/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:46:48 by amak              #+#    #+#             */
/*   Updated: 2024/04/11 16:38:37 by ftroiter         ###   ########.fr       */
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

static void	free_cube(t_cube *cube)
{
	int	i;

	if (cube->filepath)
		free(cube->filepath);
	i = 0;
	while (i < 4)
	{
		if (cube->texture_paths[i])
			free(cube->texture_paths[i]);
		i++;
	}
	if (cube->content)
		free_str_arr(cube->content);
	if (cube->map)
		free_str_arr(cube->map);
	free(cube->rays);
}

void	free_all(t_cube *cube)
{
	free_cube(cube);
}
