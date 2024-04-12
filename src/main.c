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

#include <string.h> // For bzero // Later use ft_bzero

#include "cub3D.h" // Maybe use Rrealtive path, since Makefile 

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
	bzero(cube, sizeof(t_cube));
	// setup_properties(cube); // Avoid this in ONE LINE :OMG! :D
	setup_textures(cube);
	// setup_rgb(cube); // Avoid this also in one line OMG! for the norm :D
}

int	main(int argc, char **argv)
{
	t_cube	*cube; // WTF?

	cube = calloc(sizeof(t_cube), 1);
	if (!cube)
		return (-1);

	setup(cube);
	check_file(argc, argv, cube);
	read_scene_file(cube);
	print_content(*cube, 1);
	check_content(cube);
	init_mlx(cube);
	mlx_hook(cube->graphic.win, 2, 1L << 0, key_press, cube); // Bug when turning and can't implement other appplications like updates not depending on keys (animations enemies; etc)
	mlx_hook(cube->graphic.win, 17, 0, (void *)exit_game, cube);
	// mlx
	mlx_loop(cube->graphic.mlx);
	// free(cube)
}
