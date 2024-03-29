/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:30:11 by amak              #+#    #+#             */
/*   Updated: 2024/03/22 01:33:12 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	print_content(t_file cube, int bool)
{
	int	i;

	i = -1;
	if (bool)
	{
		printf("\n\n>>> DATA EXTRACTED VALUES: <<<\n\n");
		printf(" NO: %s\n", cube.no);
		printf(" SO: %s\n", cube.so);
		printf(" WE: %s\n", cube.we);
		printf(" EA: %s\n", cube.ea);
		printf(" C: %d %d %d | full RGB: %d\n", cube.ceiling_rgb[0], 
			cube.ceiling_rgb[1], cube.ceiling_rgb[2], cube.ceiling_rgb[3]);
		printf(" F: %d %d %d | full RGB: %d\n", cube.floor_rgb[0], 
			cube.floor_rgb[1], cube.floor_rgb[2], cube.floor_rgb[3]);
		printf("\n GAME MAP: \n");
		printf(" - rows: %d\n", cube.rows);
		printf(" - collums: %d\n", cube.collums);
		printf("\n<begin in next line>\n");
		while (cube.map && cube.map[++i])
			printf("%s", cube.map[i]);
		printf("<end>");
		printf("\n------------------------------\n\n");
	}
}

int	main(int argc, char **argv)
{
	static t_file	cube;

	check_file(argc, argv, &cube);
	read_content(&cube);
	print_content(cube, 1);
	check_content(&cube);
	exit_game(NORMAL, NULL, &cube);
}
