/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:30:11 by amak              #+#    #+#             */
/*   Updated: 2024/04/09 19:06:42 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	print_content(t_cube cube, int bool)
{
	int	i, j;

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

void	setup(t_cube *cube)
{
	cube->filepath = NULL;
	cube->fd = 0;
	cube->content = NULL;
	cube->texture_paths[0] = NULL;
	cube->texture_paths[1] = NULL;
	cube->texture_paths[2] = NULL;
	cube->texture_paths[3] = NULL;
	cube->floor_rgb[0] = -1;
	cube->floor_rgb[1] = -1;
	cube->floor_rgb[2] = -1;
	cube->floor_rgb[3] = 0;
	cube->ceiling_rgb[0] = -1;
	cube->ceiling_rgb[1] = -1;
	cube->ceiling_rgb[2] = -1;
	cube->ceiling_rgb[3] = 0;
	cube->show_minimap = 0;
/* 	cube->map = NULL;
	cube->rows = 0;
	cube->columns = 0;
	cube->player.x = 0;
	cube->player.y = 0;
	cube->player.direction = 0;
	cube->graphic.mlx = NULL;
	cube->graphic.win = NULL;
	cube->graphic.image.img = NULL;
	cube->graphic.image.addr = NULL;
	cube->graphic.image.bits_per_pixel = 0;
	cube->graphic.image.line_length = 0;
	cube->graphic.image.endian = 0; */
}

int	main(int argc, char **argv)
{
	static t_cube	cube;
	setup(&cube);
	check_file(argc, argv, &cube);
	read_scene_file(&cube);
	print_content(cube, 1);
	check_content(&cube);
	init_mlx(&cube);
	mlx_hook(cube.graphic.win, 2, 1L << 0, key_press, &cube);
	mlx_hook(cube.graphic.win, 17, 0, (void *)exit_game, &cube);
	mlx_loop(cube.graphic.mlx);
}
