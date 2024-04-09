/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:31:24 by amak              #+#    #+#             */
/*   Updated: 2024/04/09 00:41:16 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	put_square(t_image *image, int x, int y, int color, int out_color)
{
	int	i;
	int	j;

	i = 0;
	while (i < PX)
	{
		j = 0;
		while (j < PX)
		{
			if (i == 0 || j == 0 || i == PX - 1 || j == PX - 1)
				my_mlx_pixel_put(image, x + i, y + j, out_color);
			else
				my_mlx_pixel_put(image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

static void	put_grid(t_image *image, t_file *file)
{
	int	y;
	int	x;

	y = 0;
	while (y < file->rows)
	{
		x = 0;
		while (x < file->columns - 1)
		{
			if (file->map[y][x] == '1' || file->map[y][x] == '\n')
				put_square(image, x * PX, y * PX, 0x00dfdfdf, 0x00ff0000);
			else if (file->map[y][x] == '0' || 
				ft_strchr("NSEW", file->map[y][x]))
				put_square(image, x * PX, y * PX, 0x00000000, 0x00ff0000);
			x++;
		}
		y++;
	}
}

static void	put_player(t_image *image, t_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (y < PLYLEN)
	{
		x = 0;
		while (x < PLYLEN)
		{
			my_mlx_pixel_put(image, player->position.x - (PLYLEN / 2) + x, 
				player->position.y -(PLYLEN / 2) + y, 0x00ffff00);
			x++;
		}
		y++;
	}
	y = 1;
	while (y <= PLYLEN)
	{
		my_mlx_pixel_put(image, 
			player->position.x + (y * player->direction.x), 
			player->position.y + (y * player->direction.y), 0x00ff0000);
		y++;
	}
}

void	draw_ray(t_image *image, t_player *player, t_file *file, float angle)
{
	int		i;
	t_ray	ray;

	i = 1;
	castray(&ray, player, file, angle);
	while (i <= (int)ray.length)
	{
		my_mlx_pixel_put(image, player->position.x + (i * cos(angle)),
			player->position.y + (i * sin(angle)), 0x0000ff00);
		i++;
	}
}

void	draw_map(t_file *file, t_window *graphic)
{
	int		i;
	float	angle;
	float	sum_angle;

	i = 1;
	angle = file->player.angle - (15 * UANGLE);
	mlx_clear_window(graphic->mlx, graphic->win);
	put_grid(&graphic->image, file);
	put_player(&graphic->image, &file->player);
	draw_ray(&graphic->image, &file->player, file, file->player.angle);
	while (i <= 30)
	{
		sum_angle = angle + (i * UANGLE);
		if (sum_angle < 0)
			sum_angle += (2 * PI);
		if (sum_angle > (2 * PI))
			sum_angle -= (2 * PI);
		draw_ray(&graphic->image, &file->player, file, angle + (i * UANGLE));
		i++;
	}
	mlx_put_image_to_window(graphic->mlx, graphic->win, graphic->image.img, 
		0, 0);
}
