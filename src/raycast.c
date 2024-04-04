/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:17:32 by amak              #+#    #+#             */
/*   Updated: 2024/04/05 00:11:25 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int		offsety(int y, float angle)
{
	int 	i;
	
	i = 0;
	if (angle < PI)
	{
		while ((i * PX) <= y)
			i++;
		return ((i * PX) - y);
	}
	if (angle > PI)
	{
		while ((i * PX) <= y)
			i++;
		i--;
		return (y - (i * PX));
	}
	printf("horizontal= %d", i);
	return (0);
}

static int		offsetx(int x, float angle)
{
	int 	i;
	
	i = 0;
	if (angle > (PI / 2) && angle < ((3 * PI) / 2))
	{
		while ((i * PX) <= x)
			i++;
		i--;
		return (x - (i * PX));
	}
	if (angle < (PI / 2) || angle > ((3 * PI) / 2))
	{
		while ((i * PX) <= x)
			i++;
		return ((i * PX) - x);
	}
	printf("vertical= %d", i);
	return (0);
}

static int calc_xdist(int x, int adj, float angle)
{
	int	result;
	int	int_angle;
	int	ninety;
	int	twoseventy;
	
	result = 0;
	int_angle = (int)(angle * 1000000);
	ninety = (int)(((PI / 2)) * 1000000);
	twoseventy = (int)(((3 * PI) / 2) * 1000000);
	printf("%d %d %d\n", int_angle, ninety, twoseventy);
	if (int_angle == ninety || int_angle == twoseventy)
		return (0);
	result = fabs(adj / cos(angle));
	return (result);
}

static int calc_ydist(int y, int opose, float angle)
{
	int	result;
	int	int_angle;
	int	oneeighty;

	result = 0;
	int_angle = (int)(angle * 1000000);
	oneeighty = (int)(PI * 1000000);
	
	if (int_angle == oneeighty || int_angle == 0)
		return (0);
	result = fabs(opose / sin(angle));
	return (result);
}

void	castray(t_image *image, t_player *player, t_file *file, float angle)
{
	int	ry;
	int	rx;
	int i;
	int oy;
	int ox;
	int dy;
	int dx;
	float ra;
	int shortdist;
	int total;
	int	stop;

	stop = 0;
	total = 0;
	ry = (int)player->position.y;
	rx = (int)player->position.x;
	ra = player->angle;
	printf("pY= %f | px= %f\n", player->position.y, player->position.x);
	printf("rY= %d | rx= %d | angle= %f\n", ry, rx, ra);
	oy = offsety(ry, ra);
	ox = offsetx(rx, ra);
	printf("oy= %d\n", oy);
	printf("ox= %d\n", ox);
	// while(!stop)
	// {
		dy = calc_ydist(ry, oy, ra);
		dx = calc_xdist(rx, ox, ra);
		printf("hip_y= %d\n", dy);
		printf("hip_x= %d\n", dx);
		shortdist = 0;
		if (!dy)
			shortdist = dx;
		else if (!dx)
			shortdist = dy;
		else if (dy <= dx)
			shortdist = dy;
		else
			shortdist = dx;
		// total += shortdist;
		// ry += shortdist * player->direction.y;
		// rx += shortdist * player->direction.x;
		printf("rY= %d | rx= %d | angle= %f\n", ry, rx, ra);
	// 	if (check_wall(ry, rx, file->map))
	// 		stop = 1;
	// }
	i = 1;
	while (i <= shortdist)
	{
		my_mlx_pixel_put(image, 
			player->position.x + (i * cos(angle)), 
			player->position.y + (i * sin(angle)), 0x0000ff00);
		i++;
	}
}
