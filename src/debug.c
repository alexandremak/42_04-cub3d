/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:44:04 by facu              #+#    #+#             */
/*   Updated: 2024/04/09 20:44:46 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	print_content(t_cube cube, int bool)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (bool)
	{
		printf("\n\n>>> DATA EXTRACTED VALUES: <<<\n\n");
		while (j < 4)
		{
			printf(" T%d: %s\n", j, cube.texture_paths[j]);
			j++;
		}
		printf(" C: %d %d %d | full RGB: %d\n", cube.ceiling_rgb[0],
			cube.ceiling_rgb[1], cube.ceiling_rgb[2], cube.ceiling_rgb[3]);
		printf(" F: %d %d %d | full RGB: %d\n", cube.floor_rgb[0],
			cube.floor_rgb[1], cube.floor_rgb[2], cube.floor_rgb[3]);
		printf("\n\n>>> GAME MAP:: <<<\n\n");
		printf(" - rows: %d\n", cube.rows);
		printf(" - columns: %d\n", cube.columns);
		printf("<start after the next line>\n");
		while (cube.map && cube.map[++i])
			printf("%s", cube.map[i]);
		printf("<end>");
		printf("\n\n");
	}
}
