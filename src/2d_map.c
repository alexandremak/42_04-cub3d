/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:31:24 by amak              #+#    #+#             */
/*   Updated: 2024/04/09 16:34:43 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	draw_square(t_image *image, int x, int y, int color, int map_scale)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_scale)
	{
		j = 0;
		while (j < map_scale)
		{
			if (i == 0 || j == 0 || i == map_scale - 1 || j == map_scale - 1)
				my_mlx_pixel_put(image, x + i, y + j, RED);
			else
				my_mlx_pixel_put(image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

static void draw_grid(t_image *image, t_cube *cube, int map_scale)
{
	int y = 0;
	while (y < cube->rows)
	{
		int x = 0;
		while (x < cube->columns - 1)
		{
			char cell = cube->map[y][x];
			if (cell == '1')
				draw_square(image, x * map_scale, y * map_scale, LIGHT_GREY, map_scale);
			else if (cell != '\n' && cell != '\0' && (cell == '0' || ft_strchr("NSEW", cell)))
				draw_square(image, x * map_scale, y * map_scale, BLACK, map_scale);
			x++;
		}
		y++;
	}
}

static void	draw_player(t_image *image, t_player *player, int map_scale)
{
	int	y;
	int	x;
	float px_division = (float)PX / map_scale;
	int player_x = round(player->position.x / px_division);
	int player_y = round(player->position.y / px_division);
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

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

void	draw_minimap(t_cube *cube, t_window *graphic)
{
	int		i;
	float	angle;
	int		map_scale;
	
	i = 1;
	angle = cube->player.angle - (15 * UANGLE);
    map_scale = min(SCREEN_WIDTH / cube->columns, SCREEN_HEIGHT / cube->rows);
	draw_grid(&graphic->image, cube, map_scale);
	draw_player(&graphic->image, &cube->player, map_scale);
	//draw_ray_scaled(&graphic->image, &cube->player, file, cube->player.angle, map_scale);
	/*while (i <= 30)
	{
		draw_ray(&graphic->image, &cube->player, file, angle + (i * UANGLE));
		i++;
	}*/
	mlx_put_image_to_window(graphic->mlx, graphic->win, graphic->image.img, 
		0, 0);
}
