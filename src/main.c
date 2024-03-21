/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:30:11 by amak              #+#    #+#             */
/*   Updated: 2024/03/20 21:57:23 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int argc, char **argv)
{
	static t_file	cube;
	int i;

	i = 0;
	check_file(argc, argv, &cube);
	read_content(&cube);
	printf("\n\n>>> DATA EXTRACTED VALUES: <<<\n");
	printf("NO: %s\n", cube.no);
	printf("SO: %s\n", cube.so);
	printf("WE: %s\n", cube.we);
	printf("EA: %s\n", cube.ea);
	printf("C: %d %d %d | %d\n", cube.ceiling_rgb[0], cube.ceiling_rgb[1], \
			cube.ceiling_rgb[2], cube.ceiling_rgb[3]);
	printf("F: %d %d %d | %d\n", cube.floor_rgb[0], cube.floor_rgb[1], \
			cube.floor_rgb[2], cube.floor_rgb[3]);
	printf("\n>>>>>Real map: \n");
	while(cube.map && cube.map[i])
	{
		printf("%s", cube.map[i]);
		i++;
	}
	check_content(&cube);
	exit_game(NORMAL, NULL, &cube);
}
