/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:53:37 by amak              #+#    #+#             */
/*   Updated: 2024/03/22 00:08:07 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	file_ext_ok(char *filepath)
{
	int		size;
	int		res;

	res = 0;
	if (!filepath)
		return (0);
	size = (int)ft_strlen(filepath);
	if (size > 4)
		if (filepath[size - 1] == 'b')
			if (filepath[size - 2] == 'u')
				if (filepath[size - 3] == 'c')
					if (filepath[size - 4] == '.')
						res = 1;
	return (res);
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
		exit_game(ERROR, "Invalid number of arguments!", file);
	file->filepath = ft_strtrim(argv[1], " \t\n\v\f\r");
	if (file->filepath == NULL)
		exit_game(ERROR, "Inserted blank filepath or filename!", file);
	if (!file_ext_ok(file->filepath))
		exit_game(ERROR, "Scene description file incorrect extension!", file);
	if (!file_exists(file->filepath, file))
		exit_game(ERROR, "Scene description file doesn't exist!", file);
}
