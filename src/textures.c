/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:05:49 by ftroiter          #+#    #+#             */
/*   Updated: 2024/04/09 20:38:15 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	load_texture(t_cube *cube, t_texture *tx, char *path)
{
	tx->image.img = mlx_xpm_file_to_image(cube->graphic.mlx, path, &tx->width,
			&tx->height);
	if (tx->image.img == NULL)
		exit_error("Error: Failed to load texture\n", cube);
	tx->image.addr = mlx_get_data_addr(tx->image.img, &tx->image.bits_per_pixel,
			&tx->image.line_length, &tx->image.endian);
	if (tx->image.addr == NULL)
		exit_error("Error: Failed to get data address for texture\n", cube);
}

void	load_textures(t_cube *cube)
{
	int			i;
	t_texture	*tx;

	i = 0;
	while (i < MAX_TEXTURES)
	{
		tx = &cube->textures[i];
		load_texture(cube, tx, cube->texture_paths[i]);
		i++;
	}
}

int	get_texture_color(t_cube *file, int y, int offset_x, t_ray ray)
{
	t_texture	texture;
	int			offset[2];
	int			dist_to_top;
	int			color;

	texture = file->textures[ray.wall_texture];
	offset[0] = offset_x;
	dist_to_top = y + (ray.wall_height / 2) - (SCREEN_HEIGHT / 2);
	offset[1] = (dist_to_top * ((float)texture.height / ray.wall_height));
	color = *(unsigned int *)(texture.image.addr + (offset[1]
				* texture.image.line_length + offset[0]
				* (texture.image.bits_per_pixel / 8)));
	return (color);
}
