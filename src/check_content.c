/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:38:34 by amak              #+#    #+#             */
/*   Updated: 2024/04/11 16:19:01 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	check_rgb(t_cube *cube, int *rgb_values)
{
	int	i;

	i = 0;
	if (rgb_values[3] == 0)
		exit_error("Scene description: incomplete rgb values", cube);
	while (i < 3)
	{
		if (rgb_values[i] < 0 || rgb_values[i] > 255)
			exit_error("Scene description: wrong rgb values", cube);
		i++;
	}
}

void	check_content(t_cube *cube)
{
	if (!texture_paths_ok(cube))
		exit_error("Scene description: incomplete textures", cube);
	check_rgb(cube, cube->floor_rgb);
	check_rgb(cube, cube->ceiling_rgb);
	check_map(cube, cube->map);
	printf("\nMap OK!\n");
}
