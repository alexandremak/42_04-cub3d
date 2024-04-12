/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:44:04 by facu              #+#    #+#             */
/*   Updated: 2024/04/11 15:38:18 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

#include "../inc/cub3D.h"

void	print_textures(t_cube cube)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		printf(" T%d: %s\n", i, cube.texture_paths[i]);
		i++;
	}
}

void	print_rgb_values(t_cube cube)
{
	printf(" C: %d %d %d | full RGB: %d\n", cube.ceiling_rgb[0],
		cube.ceiling_rgb[1], cube.ceiling_rgb[2], cube.ceiling_rgb[3]);
	printf(" F: %d %d %d | full RGB: %d\n", cube.floor_rgb[0],
		cube.floor_rgb[1], cube.floor_rgb[2], cube.floor_rgb[3]);
}

void	print_map(t_cube cube)
{
	int	i;

	i = -1;
	printf("\n\n>>> GAME MAP:: <<<\n\n");
	printf(" - rows: %d\n", cube.rows);
	printf(" - columns: %d\n", cube.columns);
	printf("<start after the next line>\n");
	while (cube.map && cube.map[++i])
		printf("%s", cube.map[i]);
	printf("<end>");
	printf("\n\n");
}

void	print_content(t_cube cube, int debug)
{
	if (debug)
	{
		printf("\n\n>>> DATA EXTRACTED VALUES: <<<\n\n");
		print_textures(cube);
		print_rgb_values(cube);
		print_map(cube);
	}
}
