/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:05:49 by ftroiter          #+#    #+#             */
/*   Updated: 2024/04/09 19:06:42 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void load_textures(t_cube *cube)
{
	int i = 0;
	while (i < MAX_TEXTURES)
	{
		cube->textures[i].image.img = mlx_xpm_file_to_image(cube->graphic.mlx, cube->texture_paths[i], 
			&cube->textures[i].width, &cube->textures[i].height);
		if (cube->textures[i].image.img == NULL)
			exit_error("Error: Failed to load texture\n", cube);
		cube->textures[i].image.addr = mlx_get_data_addr(cube->textures[i].image.img, 
			&cube->textures[i].image.bits_per_pixel, &cube->textures[i].image.line_length, 
			&cube->textures[i].image.endian);
		if (cube->textures[i].image.addr == NULL)
			exit_error("Error: Failed to get data address for texture\n", cube);
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

int	get_texture_color(t_cube *file, int y, int offset_x, t_ray ray, int wall_height)
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