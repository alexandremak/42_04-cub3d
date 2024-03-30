/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:13:17 by amak              #+#    #+#             */
/*   Updated: 2024/03/29 21:30:35 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	check_wall(int posy, int posx, char **map)
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
		check_wall(posy - 4, posx - 4, map) || 
		check_wall(posy - 4, posx + 4, map) || 
		check_wall(posy + 4, posx - 4, map) || 
		check_wall(posy + 4, posx + 4, map));
}

void	move(t_player *player, char c, char **map)
{
	int	i;
	
	i = 1;
	while (i <= PACE)
	{
		if (c == 'W')
		{
			if (!check_move_nok(player->position.y + player->direction.y, 
					player->position.x + player->direction.x, map))
			{
				player->position.y += player->direction.y;
				player->position.x += player->direction.x;
			}
		}
		else if (c == 'S')
		{
			if (!check_move_nok(player->position.y - player->direction.y, 
					player->position.x - player->direction.x, map))
			{
				player->position.y -= player->direction.y;
				player->position.x -= player->direction.x;
			}
		}
		i++;
	}
}
