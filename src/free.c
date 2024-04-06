/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:46:48 by amak              #+#    #+#             */
/*   Updated: 2024/04/05 16:38:00 by ftroiter         ###   ########.fr       */
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
	if (file->no)
		free(file->no);
	if (file->so)
		free(file->so);
	if (file->we)
		free(file->we);
	if (file->ea)
		free(file->ea);
	if (file->content)
		free_str_arr(file->content);
	if (file->map)
		free_str_arr(file->map);
}

void	free_all(t_file *file)
{
	free_file(file);
}
