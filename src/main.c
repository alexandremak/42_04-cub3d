/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:30:11 by amak              #+#    #+#             */
/*   Updated: 2024/04/07 23:42:47 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	print_content(t_file cube, int bool)
{
	int	i, j;

	i = -1;
	j = 0;
	if (bool)
	{
		printf("\n\n>>> DATA EXTRACTED VALUES: <<<\n\n");
		while (j < 4)
			printf(" T: %s\n", cube.texture_paths[j++]);
		printf(" C: %d %d %d | full RGB: %d\n", cube.ceiling_rgb[0], 
			cube.ceiling_rgb[1], cube.ceiling_rgb[2], cube.ceiling_rgb[3]);
		printf(" F: %d %d %d | full RGB: %d\n", cube.floor_rgb[0], 
			cube.floor_rgb[1], cube.floor_rgb[2], cube.floor_rgb[3]);
		printf("\n GAME MAP: \n");
		printf(" - rows: %d\n", cube.rows);
		printf(" - columns: %d\n", cube.columns);
		printf("\n<begin in next line>\n");
		while (cube.map && cube.map[++i])
			printf("%s", cube.map[i]);
		printf("<end>");
		printf("\n------------------------------\n\n");
	}
}



int	main(int argc, char **argv)
{
	static t_file	cube;

	check_file(argc, argv, &cube);
	read_content(&cube);
	print_content(cube, 1);
	check_content(&cube);

	init_mlx(&cube);
	mlx_hook(cube.graphic.win, 2, 1L << 0, key_press, &cube);
	mlx_hook(cube.graphic.win, 17, 0, (void *)exit_game, &cube);
	mlx_loop(cube.graphic.mlx);
}
