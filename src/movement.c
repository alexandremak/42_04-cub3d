/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:13:17 by amak              #+#    #+#             */
/*   Updated: 2024/04/11 16:15:58 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_wall(double posy, double posx, t_cube *cube)
{
	int	y;
	int	x;

	y = posy / PX;
	x = posx / PX;
	
	if (x >= cube->columns || y >= cube->rows || cube->map[y][x] == '1')
		return (1);
	return (0);
}

static int	check_move_nok(int posy, int posx, t_cube *cube)
{
	return (check_wall(posy, posx, cube) || check_wall(posy - (PLYLEN / 2), posx
			- (PLYLEN / 2), cube) || check_wall(posy - (PLYLEN / 2), posx
			+ (PLYLEN / 2), cube) || check_wall(posy + (PLYLEN / 2), posx
			- (PLYLEN / 2), cube) || check_wall(posy + (PLYLEN / 2), posx
			+ (PLYLEN / 2), cube));
}

void	move_player(t_player *p, double dir_y, double dir_x, t_cube *cube)
{
	if (!check_move_nok(p->position.y + dir_y, p->position.x + dir_x, cube))
	{
		p->position.y += dir_y;
		p->position.x += dir_x;
	}
}

void	move(t_player *p, int keycode, t_cube *cube)
{
	int	i;

	i = 0;
	while (i < PACE)
	{
		if (keycode == W)
			move_player(p, p->direction.y, p->direction.x, cube);
		else if (keycode == S)
			move_player(p, -p->direction.y, -p->direction.x, cube);
		else if (keycode == A)
			move_player(p, -p->direction.x, p->direction.y, cube);
		else if (keycode == D)
			move_player(p, p->direction.x, -p->direction.y, cube);
		i++;
	}
}
