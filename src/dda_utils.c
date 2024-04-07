/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:09:38 by amak              #+#    #+#             */
/*   Updated: 2024/04/07 19:24:21 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	offsety(int y, float angle)
{
	int	i;
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
	return (res);
}

int	offsetx(int x, float angle)
{
	int	i;
	int	res;

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
	return (res);
}

float	calc_xdist(int adj, float angle)
{
	int	result;
	int	int_angle;
	int	ninety;
	int	twoseventy;

	result = 0;
	int_angle = (int)(angle * 1000000) - 1;
	ninety = (int)(((PI / 2)) * 1000000);
	twoseventy = (int)(((3 * PI) / 2) * 1000000);
	if (int_angle == ninety || int_angle == twoseventy)
		return (0);
	result = fabs(adj / cos(angle));
	return (result);
}

float	calc_ydist(int opose, float angle)
{
	int	result;
	int	int_angle;
	int	oneeighty;

	result = 0;
	int_angle = (int)(angle * 1000000);
	oneeighty = (int)(PI * 1000000) + 1;
	if (int_angle == oneeighty || int_angle == 0)
		return (0);
	result = fabs(opose / sin(angle));
	return (result);
}

void	add_small_lenght(t_ray *ray, float disty, float distx)
{
	if (distx == 0 || (disty && disty <= distx))
	{
		if (ray->direction.y < 0)
			ray->y -= ray->offY;
		else
			ray->y += ray->offY;
		ray->x += disty * ray->direction.x;
		ray->length += disty;
	}
	else if (disty == 0 || (distx && disty > distx))
	{
		if (ray->direction.x < 0)
			ray->x -= ray->offX;
		else
			ray->x += ray->offX;
		ray->y += distx * ray->direction.y;
		ray->length += distx;
	}
}
