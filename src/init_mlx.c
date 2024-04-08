/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:05:31 by amak              #+#    #+#             */
/*   Updated: 2024/04/08 01:21:00 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"


void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel_to_image(t_image *image_data, int x, int y, int color)
{
	char			*pixel_address;
	unsigned int	*pixel_location;

	pixel_address = image_data->addr + (y * image_data->line_length + x * 
			(image_data->bits_per_pixel / 8));
	pixel_location = (unsigned int *)pixel_address;
	*pixel_location = color;
}

void load_textures(t_file *cube)
{
	int i = 0;
	while (i < MAX_TEXTURES)
	{
		cube->textures[i].image.img = mlx_xpm_file_to_image(cube->graphic.mlx, cube->texture_paths[i], 
			&cube->textures[i].width, &cube->textures[i].height);
		if (cube->textures[i].image.img == NULL)
			exit_error("Error: Failed to load texture %d\n", cube);
		cube->textures[i].image.addr = mlx_get_data_addr(cube->textures[i].image.img, 
			&cube->textures[i].image.bits_per_pixel, &cube->textures[i].image.line_length, 
			&cube->textures[i].image.endian);
		if (cube->textures[i].image.addr == NULL)
			exit_error("Error: Failed to get data address for texture %d\n", cube);
		i++;
	}
	printf("\n\n>>> TEXTURES LOADED: <<<\n\n");
	i = 0;
	while (i < MAX_TEXTURES)
	{
		printf("texture %d: path: %s, width: %d, height: %d\n", i, cube->texture_paths[i], cube->textures[i].width, cube->textures[i].height);
		i++;
	}
}

void	init_mlx(t_file *file)
{
	file->graphic.mlx = mlx_init();
	file->graphic.win = mlx_new_window(file->graphic.mlx, 
			(file->columns - 1) * PX, file->rows * PX, "Cub3d - 2D Map");
	file->graphic.image.img = mlx_new_image(file->graphic.mlx, 
			(file->columns - 1) * PX, file->rows * PX);
	file->graphic.image.addr = mlx_get_data_addr(file->graphic.image.img, 
			&(file->graphic.image.bits_per_pixel), 
			&file->graphic.image.line_length, 
			&file->graphic.image.endian);
	load_textures(file);
	draw_map(file, &file->graphic);
}

int	key_press(int keycode, t_file *file)
{
	if (keycode == ESC)
		exit_game(file);
	else
	{
		if (keycode == W || keycode == S || keycode == A || keycode == D)
			move(&file->player, keycode, file->map);
		else if (keycode == LA)
		{
			file->player.angle -= (PI / PIDIVUNITS);
			if (file->player.angle < 0)
				file->player.angle += (2 * PI);
			file->player.direction.x = cos(file->player.angle);
			file->player.direction.y = sin(file->player.angle);
		}
		else if (keycode == RA)
		{
			file->player.angle += (PI / PIDIVUNITS);
			if (file->player.angle > (2 * PI))
				file->player.angle -= (2 * PI);
			file->player.direction.x = cos(file->player.angle);
			file->player.direction.y = sin(file->player.angle);
		}
		draw_map(file, &file->graphic);
	}
	return (0);
}
