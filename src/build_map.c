/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:31:24 by amak              #+#    #+#             */
/*   Updated: 2024/03/29 17:46:38 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	put_wall(void *mlx, void *win, int x, int y)
{
	int	i;
	int	j;

	i = 1;
	while (i < (PX - 1))
	{
		j = 1;
		while (j < (PX - 1))
		{
			mlx_pixel_put(mlx, win, x + i, y + j, 0xdfdfdf);
			j++;
		}
		i++;
	}
}

static void	put_grid(void *mlx, void *win, t_file *file)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < file->rows)
	{
		x = 0;
		while (x < file->collums)
		{
			if (file->map[y][x] == '1')
				put_wall(mlx, win, x * PX, y * PX);
			x++;
		}
		y++;
	}
}

static void	put_player(void *mlx, void *win, t_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			mlx_pixel_put(mlx, win, player->position.x - 4 + x, 
				player->position.y - 4 + y, 0xffff00);
			x++;
		}
		y++;
	}
	y = 1;
	while (y <= 10)
	{
		mlx_pixel_put(mlx, win, player->position.x + (y * player->direction.x), 
			player->position.y + (y * player->direction.y), 0xff0000);
		y++;
	}
}

void	draw_map(t_file *file, t_windows *graphic)
{
	mlx_clear_window(graphic->mlx, graphic->win);
	put_grid(graphic->mlx, graphic->win, file);
	put_player(graphic->mlx, graphic->win, &file->player);
}
