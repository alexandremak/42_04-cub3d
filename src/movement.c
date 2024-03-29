/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:13:17 by amak              #+#    #+#             */
/*   Updated: 2024/03/28 22:52:13 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_wall(int posy, int posx, char **map)
{
	int y;
	int x;
	
	y = posy / PX;
	x = posx / PX;
	
	printf("posy = %d | posx = %d \n", posy, posx);
	printf("y = %d | x = %d \n" , y, x);
	printf("maps value = %c \n", map[y][x]);
	if (map[y][x] == '1')
	{
		printf("Is wall!\n");
		return (1);
	}
	return (0);
}
