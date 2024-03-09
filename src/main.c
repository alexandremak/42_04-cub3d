/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:30:11 by amak              #+#    #+#             */
/*   Updated: 2024/03/09 16:53:14 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int argc, char **argv)
{
	static t_file	cube;

	check_file(argc, argv, &cube);
	read_content(&cube);
	printf("NO: %s\n", cube.no);
	printf("SO: %s\n", cube.so);
	printf("WE: %s\n", cube.we);
	printf("EA: %s\n", cube.ea);
	printf("C: %d %d %d\n", cube.ceiling_rgb[0], cube.ceiling_rgb[1], \
			cube.ceiling_rgb[2]);
	printf("F: %d %d %d\n", cube.floor_rgb[0], cube.floor_rgb[1], \
			cube.floor_rgb[2]);
	exit_game(NORMAL, &cube);
}
