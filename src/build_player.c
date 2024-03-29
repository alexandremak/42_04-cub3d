/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:31:24 by amak              #+#    #+#             */
/*   Updated: 2024/03/28 23:13:13 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	put_grid(void *mlx, void *win, t_file *file)
{
	int	y;
	int	x;
	int	i;
	int j;
	
	y = 0;
	x = 0;
	while (y < file->rows)
	{
		x = 0;
		while (x < file->collums)
		{
			if (file->map[y][x] == '1')
			{
				i = 0;
				while (i < (PX - 1))
				{
					j = 0;
					while (j < (PX - 1))
					{
						mlx_pixel_put(mlx, win, x * PX + i, y * PX + j, 0xdfdfdf);
						j++;
					}
					i++;
				}
			}
			x++;
		}
		y++;
	}
	printf("Aqui!\n");
}

void	draw_player(t_file *file, t_windows *graphic)
{
	mlx_clear_window(graphic->mlx, graphic->win);
	put_grid(graphic->mlx, graphic->win, file);
	mlx_put_image_to_window(graphic->mlx, graphic->win, file->player.img, 
		(int)file->player.position.x, (int)file->player.position.y);
}
