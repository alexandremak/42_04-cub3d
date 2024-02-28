/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:53:37 by amak              #+#    #+#             */
/*   Updated: 2024/02/27 23:45:59 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

    // parsing file:
	//	- validate file extension
    //  - init values
    //  - validate input
    //  - creating matrix
    //  - validate map:
    //      - only "1,0,N,SE,W"
    //      - closed/surrounded

static int	file_ext_ok(char *filepath)
{
	int	size;

	size = ft_strlen(filepath);
	if (size >= 5)
		if (filepath[size - 1] == 'b')
			if (filepath[size - 2] == 'u')
				if (filepath[size - 3] == 'c')
					if (filepath[size - 4] == '.')
						return (1);
	return (0);
}
void parsing(int argc, char **argv, t_file *file)
{
	if (argc != 2)
		exit_game(ARGC_ERROR, file);
	if (!file_ext_ok(argv[1]))
		exit_game(EXT_ERROR, file);
	// no file
}
