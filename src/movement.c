/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:13:17 by amak              #+#    #+#             */
/*   Updated: 2024/04/08 22:54:05 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_wall(int posy, int posx, char **map)
{
	int	y;
	int	x;

	y = posy / PX;
	x = posx / PX;
	if (map[y][x] == '1')
	{
		return (1);
	}
	return (0);
}

static int	check_move_nok(int posy, int posx, char **map)
{
	return (check_wall(posy, posx, map) || 
		check_wall(posy - (PLYLEN / 2), posx - (PLYLEN / 2), map) || 
		check_wall(posy - (PLYLEN / 2), posx + (PLYLEN / 2), map) || 
		check_wall(posy + (PLYLEN / 2), posx - (PLYLEN / 2), map) || 
		check_wall(posy + (PLYLEN / 2), posx + (PLYLEN / 2), map));
}

void	move(t_player *player, int keycode, char **map)
{
	int	i;

	i = 1;
	while (i <= PACE)
	{
		if (keycode == W)
		{
			if (!check_move_nok(player->position.y + player->direction.y, 
					player->position.x + player->direction.x, map))
			{
				player->position.y += player->direction.y;
				player->position.x += player->direction.x;
			}
		}
		else if (keycode == S)
		{
			if (!check_move_nok(player->position.y - player->direction.y, 
					player->position.x - player->direction.x, map))
			{
				player->position.y -= player->direction.y;
				player->position.x -= player->direction.x;
			}
		}
		else if (keycode == A)
		{
			if (!check_move_nok(player->position.y + -(player->direction.x), 
					player->position.x + player->direction.y, map))
			{
				player->position.y += -(player->direction.x);
				player->position.x += player->direction.y;
			}
		}
		else if (keycode == D)
		{
			if (!check_move_nok(player->position.y + player->direction.x, 
					player->position.x + -(player->direction.y), map))
			{
				player->position.y += player->direction.x;
				player->position.x += -(player->direction.y);
			}
		}
		i++;
	}
}
