/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:38:34 by amak              #+#    #+#             */
/*   Updated: 2024/03/25 22:22:39 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	check_rgb(t_file *file, int *rgb_values)
{
	int	i;

	i = 0;
	if (rgb_values[3] == 0)
		exit_error("Scene description file with incomplete rgb values!", file);
	while (i < 3)
	{
		if (rgb_values[i] < 0 || rgb_values[i] > 255)
			exit_error("Scene description file with wrong rgb values!", file);
		i++;
	}
}

void	check_content(t_file *file)
{
	if (!file->no || !file->so || !file->we || !file->ea)
		exit_error("Scene description file with incomplete textures!", file);
	check_rgb(file, file->floor_rgb);
	check_rgb(file, file->ceiling_rgb);
	check_map(file, file->map);
	printf("\nMap OK!\n");
}
