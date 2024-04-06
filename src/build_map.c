/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:31:24 by amak              #+#    #+#             */
/*   Updated: 2024/04/06 15:53:52 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	clean_image(t_file *file, t_image *image)
{
	int x;
	int y;
		
	x = 0;
	y = 0;
	while (x < ((file->collums - 1) * PX))
	{
		y = 0;
		while (y < file->rows * PX)
		{
			my_mlx_pixel_put(image, x, y, 0x00000000);
			y++;
		}
		x++;
	}
}

void put_pixel_to_image(t_image *image_data, int x, int y, int color)
{
  char		      *pixel_address;
	unsigned int	*pixel_location;
	
	pixel_address = image_data->addr + (y * image_data->line_length + x * (image_data->bits_per_pixel / 8));
    pixel_location = (unsigned int*)pixel_address;
    *pixel_location = color;
}

static void	put_square(t_image *image, int x, int y, int color, int border_color)
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
				my_mlx_pixel_put(image, x + i, y + j, border_color);
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
			if (file->map[y][x] == '1')
				put_square(image, x * PX, y * PX, 0x00dfdfdf, 0x00ff0000);
			else if (file->map[y][x] == '0'|| ft_strchr("NSEW",file->map[y][x]))
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

void	draw_map(t_file *file, t_windows *graphic)
{
	int i;

	i = 1;
	mlx_clear_window(graphic->mlx, graphic->win);
	clean_image(file, &graphic->image);
	put_grid(&graphic->image, file);
	put_player(&graphic->image, &file->player);
	castray(&graphic->image, &file->player, file, file->player.angle);
	// while (i <= 30)
	// {
	// 	castray(&graphic->image, &file->player, file, (i * ANGLE) + file->player.angle);
	// 	castray(&graphic->image, &file->player, file, (-i * ANGLE) + file->player.angle);
	// 	i++;
	// }
	mlx_put_image_to_window(graphic->mlx, graphic->win, graphic->image.img, 
							0 , 0);
}
