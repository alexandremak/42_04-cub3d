/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:53:37 by amak              #+#    #+#             */
/*   Updated: 2024/04/11 16:23:09 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	texture_paths_ok(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < MAX_TEXTURES && cube->texture_paths[i])
		i++;
	return (i == MAX_TEXTURES);
}

int	text_rgb_ok(t_cube *cube)
{
	int	res;

	res = 0;
	if (texture_paths_ok(cube) && cube->ceiling_rgb[3] && cube->floor_rgb[3])
		res = 1;
	return (res);
}

static int	file_ext_ok(char *filepath)
{
	char	*extension;

	if (!filepath)
		return (0);
	extension = ft_strrchr(filepath, '.');
	if (extension && ft_strcmp(extension, ".cub") == 0)
		return (1);
	return (0);
}

static int	file_exists(char *filepath, t_cube *cube)
{
	int	res;

	res = 0;
	if (!filepath)
		return (res);
	cube->fd = open(filepath, O_RDONLY);
	if (cube->fd > -1)
		res = 1;
	return (res);
}

void	check_file(int argc, char **argv, t_cube *cube)
{
	if (argc != 2)
		exit_error("Invalid arguments", cube);
	cube->filepath = ft_strtrim(argv[1], " \t\n\v\f\r");
	if (argc != 2 || cube->filepath == NULL)
		exit_error("Invalid filepath", cube);
	if (!file_ext_ok(cube->filepath))
		exit_error("Invalid scene description extension", cube);
	if (!file_exists(cube->filepath, cube))
		exit_error("Scene description not found", cube);
}
