/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:09:38 by amak              #+#    #+#             */
/*   Updated: 2024/04/09 19:12:39 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	distance_y(int y, float angle)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (fabs(angle - 0) < TOLERANCE || fabs(angle - PI) < TOLERANCE)
		return (0);
	if (angle < PI)
	{
		while ((i * PX) <= y)
			i++;
		res = (i * PX) - y;
	}
	else if (angle > PI)
	{
		while ((i * PX) <= y)
			i++;
		i--;
		res = y - (i * PX) + 1;
	}
	return (res);
}

int	distance_x(int x, float angle)
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

float	get_x_step(int adj, float angle)
{
	float	result;
	int		int_angle;
	int		ninety;
	int		twoseventy;

	result = 0;
	int_angle = (int)(angle * 10000000) - 1;
	ninety = (int)(((PI / 2)) * 10000000);
	twoseventy = (int)(((3 * PI) / 2) * 10000000);
	if (int_angle == ninety || int_angle == twoseventy)
		return (0);
	result = fabs(adj / cos(angle));
	return (result);
}

float	get_y_step(int opose, float angle)
{
	float	result;
	int		int_angle;
	int		oneeighty;

	result = 0;
	int_angle = (int)(angle * 10000000);
	oneeighty = (int)(PI * 10000000) + 1;
	if (int_angle == oneeighty || int_angle == 0)
		return (0);
	result = fabs(opose / sin(angle));
	return (result);
}

void	increment_ray_length(t_ray *ray, float step_y, float step_x)
{
	if (step_x == 0 || (step_y && step_y <= step_x))
	{
		if (ray->direction.y < 0)
			ray->y -= ray->distance_y;
		else
			ray->y += ray->distance_y;
		ray->x += step_y * ray->direction.x;
		ray->length += step_y;
		ray->hit_vert_wall = 0;
	}
	else if (step_y == 0 || (step_x && step_y > step_x))
	{
		if (ray->direction.x < 0)
			ray->x -= ray->distance_x;
		else
			ray->x += ray->distance_x;
		ray->y += step_x * ray->direction.y;
		ray->length += step_x;
		ray->hit_vert_wall = 1;
	}
}
