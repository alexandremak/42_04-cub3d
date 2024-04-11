/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:31:24 by amak              #+#    #+#             */
/*   Updated: 2024/04/09 16:34:43 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	draw_square(t_cube *cube, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < cube->map_scale)
	{
		j = 0;
		while (j < cube->map_scale)
		{
			if (i == 0 || j == 0 || i == cube->map_scale - 1
				|| j == cube->map_scale - 1)
				my_mlx_pixel_put(&cube->graphic.image, x + i, y + j, RED);
			else
				my_mlx_pixel_put(&cube->graphic.image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

static void	draw_grid(t_cube *cube)
{
	int		y;
	int		x;
	char	cell;

	y = 0;
	while (y < cube->rows)
	{
		x = 0;
		while (x < cube->columns - 1)
		{
			cell = cube->map[y][x];
			if (cell == '1')
				draw_square(cube, x * cube->map_scale, y * cube->map_scale,
					LIGHT_GREY);
			else if (cell != '\n' && cell != '\0' && (cell == '0'
					|| ft_strchr("NSEW", cell)))
				draw_square(cube, x * cube->map_scale, y * cube->map_scale,
					BLACK);
			x++;
		}
		y++;
	}
}

static void	draw_player(t_image *image, t_player *player, int map_scale)
{
	int		y;
	int		x;
	float	px_division;
	int		player_x;
	int		player_y;

	px_division = (float)PX / map_scale;
	player_x = round(player->position.x / px_division);
	player_y = round(player->position.y / px_division);
	y = 0;
	while (y < PLYLEN)
	{
		x = 0;
		while (x < PLYLEN)
		{
			my_mlx_pixel_put(image, player_x + x, player_y + y, 0x00ffff00);
			x++;
		}
		y++;
	}
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	draw_minimap(t_cube *cube, t_window *graphic)
{
	int		i;
	float	angle;

	i = 1;
	angle = cube->player.angle - (15 * (PI / 360));
	cube->map_scale = SCREEN_HEIGHT / (3 * cube->rows);
	draw_grid(cube);
	draw_player(&graphic->image, &cube->player, cube->map_scale);
	mlx_put_image_to_window(graphic->mlx, graphic->win, graphic->image.img, 0,
		0);
}
