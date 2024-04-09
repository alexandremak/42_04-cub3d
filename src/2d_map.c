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

void	draw_square(t_image *image, int x, int y, int color, int out_color)
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

static void	draw_grid(t_image *image, t_file *file, int map_scale)
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
				draw_square(image, x * map_scale, y * map_scale, 0x00dfdfdf, 0x00ff0000);
			else if (file->map[y][x] == '0' || 
				ft_strchr("NSEW", file->map[y][x]))
				draw_square(image, x * map_scale, y * map_scale, 0x00000000, 0x00ff0000);
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

void	draw_minimap(t_file *file, t_window *graphic)
{
	int		i;
	float	angle;
	int		map_scale;
	
	i = 1;
	angle = file->player.angle - (15 * UANGLE);
    map_scale = min(SCREEN_WIDTH / file->columns, SCREEN_HEIGHT / file->rows);
	draw_grid(&graphic->image, file, map_scale);
	draw_player(&graphic->image, &file->player, map_scale);
	//draw_ray_scaled(&graphic->image, &file->player, file, file->player.angle, map_scale);
	/*while (i <= 30)
	{
		draw_ray(&graphic->image, &file->player, file, angle + (i * UANGLE));
		i++;
	}*/
	mlx_put_image_to_window(graphic->mlx, graphic->win, graphic->image.img, 
		0, 0);
}
