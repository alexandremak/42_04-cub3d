/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:05:31 by amak              #+#    #+#             */
/*   Updated: 2024/04/08 15:24:03 by ftroiter         ###   ########.fr       */
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
/*	file->graphic.win = mlx_new_window(file->graphic.mlx, 
			(file->columns - 1) * PX, file->rows * PX, "Cub3d - 2D Map");
			
	file->graphic.image.img = mlx_new_image(file->graphic.mlx, 
			(file->columns - 1) * PX, file->rows * PX); */
	file->graphic.win = mlx_new_window(file->graphic.mlx, 
			SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d - 3D Map");
	file->graphic.image.img = mlx_new_image(file->graphic.mlx, 
			SCREEN_WIDTH, SCREEN_HEIGHT);
	file->graphic.image.addr = mlx_get_data_addr(file->graphic.image.img, 
			&(file->graphic.image.bits_per_pixel), 
			&file->graphic.image.line_length, 
			&file->graphic.image.endian);
	load_textures(file);
	// draw_map(file, &file->graphic);
	// print white square in middle of screen
	raycasting(file);


}


int	get_texture_color(t_file *file, int y, int offset_x, t_ray ray, int wall_height)
{
	t_texture	texture;
	int			offset[2];
	int			dist_to_top;
	int			color;

	texture = file->textures[ray.wall_texture];
	offset[0] = offset_x;
	dist_to_top = y + (wall_height / 2) - (SCREEN_HEIGHT / 2);
	offset[1] = (dist_to_top * ((float)texture.height / wall_height)); 
	color = *(unsigned int *)(texture.image.addr + (offset[1] * texture.image.line_length + offset[0] * (texture.image.bits_per_pixel / 8)));
	return (color);
}

void	draw_wall(t_file *file, t_ray ray, int start_point[2], int end_y, int offset_x, int wall_height)
{
	int		color;
	int		y;

	y = start_point[1];
	while (y < end_y)
	{
		if (y >= 0 && y <= SCREEN_HEIGHT)
		{
			color = get_texture_color(file, y, offset_x, ray, wall_height);
			my_mlx_pixel_put(&file->graphic.image, start_point[0], y, color);
		}
		y++;
	}
}

void	draw_walls(t_file *file, t_ray *rays)
{
	int		ray;
	int		start_point[2];
	int		end_y;
	int		offset_x;
	int		wall_height;

	ray = 0;
	while (ray < SCREEN_WIDTH)
	{
		wall_height = ((PX / rays[ray].length) * PLANE_DIST);
		start_point[0] = ray;
		start_point[1] = floor(SCREEN_HEIGHT / 2) - (wall_height / 2);
		if (start_point[1] < 0)
			start_point[1] = 0;
		end_y = floor(SCREEN_HEIGHT / 2) + (wall_height / 2);
		if (end_y >= SCREEN_HEIGHT)
			end_y = SCREEN_HEIGHT - 1;
		offset_x = rays[ray].wall_hit;
		printf("Ray %d: \nstart_point[0]: %d\n start_point[1]: %d\n end_y: %d\n offset_x: %d\n wall_height: %d\n", ray, start_point[0], start_point[1], end_y, offset_x, wall_height);
		draw_wall(file, rays[ray], start_point, end_y, offset_x, wall_height);
		ray++;
	}	
}

void	raycasting(t_file *file)
{
	float	angle;
	int		pixel_column;
	t_ray		*rays;

	rays = (t_ray *)malloc(sizeof(t_ray) * SCREEN_WIDTH);
	mlx_clear_window(file->graphic.mlx, file->graphic.win);
	put_square(&file->graphic.image, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0x00ffffff, 0x00ff0000);
/* 
	angle = file->player.angle - (HALF_FOV);
	pixel_column = 0;
	while (pixel_column < SCREEN_WIDTH)
	{
		castray(&rays[pixel_column], &file->player, file, angle);
		angle += (FOV / SCREEN_WIDTH);
		pixel_column++;
	}
	int i;
	for (i = 0; i < SCREEN_WIDTH; i++) {
		printf("Ray %d: %f\n", i, rays[i].length);
	}
	draw_walls(file, rays);
	free(rays); */
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
		// draw_map(file, &file->graphic);
		raycasting(file);
	}
	return (0);
}
