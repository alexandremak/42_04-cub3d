/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:31:24 by amak              #+#    #+#             */
/*   Updated: 2024/04/04 20:20:18 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void put_pixel_to_image(t_image *image_data, int x, int y, int color) {
    char			*pixel_address;
	unsigned int	*pixel_location;
	
	pixel_address = image_data->addr + (y * image_data->line_length + x * (image_data->bits_per_pixel / 8));
    pixel_location = (unsigned int*)pixel_address;
    *pixel_location = color;
}

static void	put_square(t_image *image, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < (PX))
	{
		j = 0;
		while (j < (PX))
		{
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
	x = 0;
	while (y < file->rows)
	{
		x = 0;
		while (x < file->columns - 1)
		{
			if (file->map[y][x] == '1')
				put_square(image, x * PX, y * PX, 0x00dfdfdf);
			else if (file->map[y][x] == '0'|| ft_strchr("NSEW",file->map[y][x]))
				put_square(image, x * PX, y * PX, 0x00000000);
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
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			my_mlx_pixel_put(image, player->position.x - (PLYLEN / 2) + x, 
				player->position.y -(PLYLEN / 2) + y, 0x00ffff00);
			x++;
		}
		y++;
	}
	y = 1;
	while (y <= 10)
	{
		my_mlx_pixel_put(image, 
			player->position.x + (y * player->direction.x), 
			player->position.y + (y * player->direction.y), 0x00ff0000);
		y++;
	}
}

void	draw_map(t_file *file, t_windows *graphic)
{
	int i;

	i = 1;
	mlx_clear_window(graphic->mlx, graphic->win);
	put_grid(&graphic->image, file);
	put_player(&graphic->image, &file->player);
	castray(&graphic->image, &file->player, file, file->player.angle);
	while (i <= 30)
	{
		castray(&graphic->image, &file->player, file, (i * ANGLE) + file->player.angle);
		castray(&graphic->image, &file->player, file, (-i * ANGLE) + file->player.angle);
		i++;
	}
	mlx_put_image_to_window(graphic->mlx, graphic->win, graphic->image.img, 
							0 , 0);
}
