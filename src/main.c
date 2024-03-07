/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:30:11 by amak              #+#    #+#             */
/*   Updated: 2024/03/06 23:39:50 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int argc, char **argv)
{
	static t_file	cube;

	parsing(argc, argv, &cube);
	read_content(&cube);
	printf("NO: %s\n", cube.no);
	printf("SO: %s\n", cube.so);
	printf("WE: %s\n", cube.we);
	printf("EA: %s\n", cube.ea);
	exit_game(NORMAL, &cube);
}
