/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:53:37 by amak              #+#    #+#             */
/*   Updated: 2024/04/08 01:01:48 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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

static int	file_exists(char *filepath, t_file *file)
{
	int		res;

	res = 0;
	if (!filepath)
		return (res);
	file->fd = open(filepath, O_RDONLY);
	if (file->fd > -1)
		res = 1;
	return (res);
}

void	check_file(int argc, char **argv, t_file *file)
{
	if (argc != 2)
		exit_error("Invalid number of arguments!", file);
	file->filepath = ft_strtrim(argv[1], " \t\n\v\f\r");
	if (file->filepath == NULL)
		exit_error("Inserted blank filepath or filename!", file);
	if (!file_ext_ok(file->filepath))
		exit_error("Scene description file incorrect extension!", file);
	if (!file_exists(file->filepath, file))
		exit_error("Scene description file doesn't exist!", file);
}
