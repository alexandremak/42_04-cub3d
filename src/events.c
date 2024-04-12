/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:42:55 by ftroiter          #+#    #+#             */
/*   Updated: 2024/04/11 16:37:06 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	handle_movement(int keycode, t_cube *cube)
{
	if (keycode == W || keycode == S || keycode == A || keycode == D)
		move(&cube->player, keycode, cube);
}

void	handle_left_angle(t_cube *cube)
{
	cube->player.angle -= TURNANGLE;
	if (cube->player.angle < 0)
		cube->player.angle += (2 * PI);
	cube->player.direction.x = cos(cube->player.angle);
	cube->player.direction.y = sin(cube->player.angle);
}

void	handle_right_angle(t_cube *cube)
{
	cube->player.angle += TURNANGLE;
	if (cube->player.angle > (2 * PI))
		cube->player.angle -= (2 * PI);
	cube->player.direction.x = cos(cube->player.angle);
	cube->player.direction.y = sin(cube->player.angle);
}

void	toggle_minimap(t_cube *cube)
{
	cube->show_minimap = !cube->show_minimap;
}

int	key_press(int keycode, t_cube *cube)
{
	if (keycode == ESC)
		exit_game(cube);
	else
	{
		if (keycode == 120 || keycode == 122)
			cube->redline += ((keycode == 120) ? 1 : -1) % SCREEN_WIDTH;
		if (keycode == 99)
			printf("Redline #[%d]\n", cube->redline);
		handle_movement(keycode, cube);
		if (keycode == LA)
			handle_left_angle(cube);
		else if (keycode == RA)
			handle_right_angle(cube);
		else if (keycode == M)
			toggle_minimap(cube);
		render_scene(cube);
	}
	return (0);
}
