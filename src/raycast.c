/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:17:32 by amak              #+#    #+#             */
/*   Updated: 2024/04/02 22:15:56 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int		offsety(int y, float angle)
{
	int 	i;
	
	i = 0;
	if (angle > PI)
	{
		while ((i * PX) <= y)
			i++;
		i--;
		return ((i * PX) - y);
	}
	if (angle < PI)
	{
		while ((i * PX) <= y)
			i++;
		return ((i * PX) - y);
	}
	return (0);
}

int calc_ydist(t_player *player, int offset, float angle, char **map)
{
	int	y;
	int x;
	int result;

	result = offset;
	y = player->position.y + result;
	x = player->position.x + (result * cos(angle));
	while (!check_wall(y, x, map))
	{
		result += PX - 1;
		y = player->position.y + result;
		x = player->position.x + (result * cos(angle));
	}
	return (result);
}

void	castray(t_image *image, t_player *player, t_file *file, float angle)
{
	int	ry;
	int	rx;
	int i;
	int dy;

	ry = (int)player->position.y;
	rx = (int)player->position.x;
		dy = calc_ydist(player, offsety(ry, angle), angle, file->map);
	i = 1;
	while (i <= dy)
	{
		my_mlx_pixel_put(image, 
			player->position.x + (i * cos(angle)), 
			player->position.y + (i * sin(angle)), 0x0000ff00);
		i++;
	}
}
