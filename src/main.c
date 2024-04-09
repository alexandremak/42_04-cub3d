/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:30:11 by amak              #+#    #+#             */
/*   Updated: 2024/04/09 20:45:06 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	setup_textures(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < MAX_TEXTURES)
		cube->texture_paths[i++] = NULL;
}

void	setup_rgb(t_cube *cube)
{
	cube->floor_rgb[0] = -1;
	cube->floor_rgb[1] = -1;
	cube->floor_rgb[2] = -1;
	cube->floor_rgb[3] = 0;
	cube->ceiling_rgb[0] = -1;
	cube->ceiling_rgb[1] = -1;
	cube->ceiling_rgb[2] = -1;
	cube->ceiling_rgb[3] = 0;
}

void	setup_properties(t_cube *cube)
{
	cube->filepath = NULL;
	cube->fd = 0;
	cube->content = NULL;
	cube->show_minimap = 0;
}

void	setup(t_cube *cube)
{
	setup_properties(cube);
	setup_textures(cube);
	setup_rgb(cube);
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
