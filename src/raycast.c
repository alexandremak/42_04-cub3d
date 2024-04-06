/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:17:32 by amak              #+#    #+#             */
/*   Updated: 2024/04/06 18:53:05 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int		offsety(int y, float angle)
{
	int i;
	int	res;		
	
	i = 0;
	res = 0;
	if (angle == 0 || angle == PI)
		return (0);
	if (angle < PI)
	{
		while ((i * PX) <= y)
			i++;
		res = (i * PX) - y;
	}
	if (angle > PI)
	{
		while ((i * PX) <= y)
			i++;
		i--;
		res = y - (i * PX) + 1;
	}
	// printf("horizontal= %d  distancia= %d\n", i * PX, res);
	return (res);
}

static int		offsetx(int x, float angle)
{
	int i;
	int res;
	
	i = 0;
	res = 0;
	if (angle > (PI / 2) && angle < ((3 * PI) / 2))
	{
		while ((i * PX) <= x)
			i++;
		i--;
		res = x - (i * PX) + 1;
	}
	if (angle < (PI / 2) || angle > ((3 * PI) / 2))
	{
		while ((i * PX) <= x)
			i++;
		res = (i * PX) - x;
	}
	// printf("vertical= %d distancia= %d\n", i * PX, res);
	return (res);
}

static int calc_xdist(int x, int adj, float angle)
{
	int	result;
	int	int_angle;
	int	ninety;
	int	twoseventy;
	
	result = 0;
	int_angle = (int)(angle * 1000000) - 1;
	ninety = (int)(((PI / 2)) * 1000000);
	twoseventy = (int)(((3 * PI) / 2) * 1000000);
	// printf("xdist: angle*1000000=%d | 90=%d | 270=%d\n", int_angle, ninety, twoseventy);
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
	oneeighty = (int)(PI * 1000000) + 1;
	// printf("ydist: angle*1000000=%d | 180=%d\n", int_angle, oneeighty);
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
	float dy;
	float dx;
	int	disty;
	int distx;
	float ra;
	float shortdist;
	float total;
	int	stop;

	stop = 0;
	total = 0;
	ry = (int)player->position.y;
	rx = (int)player->position.x;
	ra = angle;
	dx = cos(angle);
	dy = sin(angle);
	i = 0;
	while(!stop)
	{
		// printf("%d TURN : ---------------\n", stop);
		// printf("ponto do raio: y= %d | x= %d\n", ry, rx);
		// printf("vector direccao: y= %f | x= %f\n", dy, dx);
		// printf("angulo direccao: %f\n", ra);
		oy = offsety(ry, angle);
		ox = offsetx(rx, angle);
		// printf("Y offset: %d\n", oy);
		// printf("X offset: %d\n", ox);
		disty = calc_ydist(ry, oy, ra);
		distx = calc_xdist(rx, ox, ra);
		// printf("Y distance: %d\n", disty);
		// printf("X distance: %d\n", distx);
		if (distx == 0 || (disty && disty <= distx))
		{
			if (dy < 0)
				ry -= oy;
			else
				ry += oy;
			// printf("sin(ra)= %f\n", sin(ra));
			rx += disty * dx;
			total += disty;
			// printf("Novo ponto do raio: y= %d | x= %d\n", ry, rx);
		}
		else if (disty == 0 || (distx && disty > distx))
		{
			if (dx < 0)
				rx -= ox;
			else
				rx += ox;
			// printf("cos(ra)= %f\n", cos(ra));
			ry += distx * dy;
			total += distx;
			// printf("Novo ponto do raio: y= %d | x= %d\n", ry, rx);
		}
		// printf("Novo ponto no mapa: y= %d | x= %d\n", ry / PX, rx / PX);
		// printf("Total: %f\n", total);
		if (check_wall(ry, rx, file->map))
			stop = 1;
		// printf("--------------------------\n");
		i++;
	}
	printf("DDA count: %d\n", i);
	i = 1;
	while (i <= (int)total)
	{
		my_mlx_pixel_put(image, 
			player->position.x + (i * cos(angle)), 
			player->position.y + (i * sin(angle)), 0x0000ff00);
		i++;
	}
}
