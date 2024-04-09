/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:53:37 by amak              #+#    #+#             */
/*   Updated: 2024/04/09 19:12:39 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	texture_paths_ok(t_cube *file)
{
	int	i;

	i = 0;
	while (i < MAX_TEXTURES && file->texture_paths[i])
		i++;
	return (i == MAX_TEXTURES);
}

int	text_rgb_ok(t_cube *file)
{
	int	res;

	res = 0;
	if (texture_paths_ok(file) && file->ceiling_rgb[3] && file->floor_rgb[3])
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

static int	file_exists(char *filepath, t_cube *file)
{
	int	res;

	res = 0;
	if (!filepath)
		return (res);
	file->fd = open(filepath, O_RDONLY);
	if (file->fd > -1)
		res = 1;
	return (res);
}

void	check_file(int argc, char **argv, t_cube *file)
{
	if (argc != 2)
		exit_error("Invalid number of arguments!", file);
	file->filepath = ft_strtrim(argv[1], " \t\n\v\f\r");
	if (argc != 2 || file->filepath == NULL)
		exit_error("Inserted blank filepath or filename!", file);
	if (!file_ext_ok(file->filepath))
		exit_error("Scene description file incorrect extension!", file);
	if (!file_exists(file->filepath, file))
		exit_error("Scene description file doesn't exist!", file);
}
