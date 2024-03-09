/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:46:48 by amak              #+#    #+#             */
/*   Updated: 2024/03/09 16:28:13 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	free_mtrx(char **mtrx)
{
	int	i;

	i = 0;
	if (*mtrx)
	{
		while (mtrx[i])
		{
			free(mtrx[i]);
			i++;
		}
		free(mtrx);
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
	if (file->map)
		free_mtrx(file->map);
}

void	free_all(t_file *file)
{
	free_file(file);
}
