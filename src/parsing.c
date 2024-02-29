/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:53:37 by amak              #+#    #+#             */
/*   Updated: 2024/02/29 00:32:57 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

    // parsing file:
	//	- validate file extension
	//	- file exists
    //  - init values
    //  - validate input
    //  - creating matrix
    //  - validate map:
    //      - only "1,0,N,SE,W"
    //      - closed/surrounded

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
			if (filepath[size - 2] ==  'u')
				if (filepath[size - 3] == 'c')
					if (filepath[size - 4] == '.')
						res = 1;
	return (res);
}

static int	file_exists(char *filepath)
{
	int 	res;
	int		fd;

	res = 0;
	if (!filepath)
		return (res);
	fd = open(filepath, O_RDONLY);
	if (fd > -1)
	{
		res = 1;
		close(fd);
	}
	return (res);
}

void parsing(int argc, char **argv, t_file *file)
{
	if (argc != 2)
		exit_game(ARGC_ERROR, file);
	file->filepath = ft_trimstr(argv[1]);
	if (!file_ext_ok(file->filepath))
		exit_game(EXT_ERROR, file);
	if (!file_exists(file->filepath))
		exit_game(NO_FILE, file);
}
