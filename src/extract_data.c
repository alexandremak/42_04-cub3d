/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:00:21 by amak              #+#    #+#             */
/*   Updated: 2024/04/09 19:06:42 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	extract_rgb(t_cube *file, int *rgb, char *splited)
{
	char	**numbers;
	int		i;
	int		error = 0;

	if (rgb[3] || !splited)
		error = 1;
	else
	{
		numbers = ft_split(splited, ',');
		if (ft_strarr_size(numbers) > 3)
			error = 1;
		else
		{
			for (i = 0; i < 3 && numbers[i]; i++)
			{
				if (ft_strlen(numbers[i]) > 4 || !ft_isdigit_str(numbers[i]))
				{
					error = 1;
					break;
				}
				rgb[i] = ft_atoi(numbers[i]);
			}
			if (i < 3)
				error = 1;
			else
				rgb[3] = 1;
		}
		free_str_arr(numbers);
	}
	if (error)
		ft_print_error(2, "Scene description", "invalid RGB values");
	return (error);
}

int	extract_txtr(t_cube *file, char *pathstr, int index)
{
	int	fd;

	fd = open(pathstr, O_RDONLY);
	if (fd < 0 || file->texture_paths[index])
	{
		close(fd);
		ft_print_error(2, "Scene description", "invalid texture values");
		return (1);
	}
	file->texture_paths[index] = ft_strdup(pathstr);
	close(fd);
	return (0);
}

int	extract_metadata(t_cube *file, char **splited)
{
	int	index;
	int	err;

	err = 0;
	index = -1;
	if (ft_strcmp(splited[0], "NO") == 0)
		index = NORTH;
	else if (ft_strcmp(splited[0], "SO") == 0)
		index = SOUTH;
	else if (ft_strcmp(splited[0], "EA") == 0)
		index = EAST;
	else if (ft_strcmp(splited[0], "WE") == 0)
		index = WEST;
	if (index != -1)
		err = extract_txtr(file, splited[1], index);
	else if (ft_strcmp(splited[0], "C") == 0)
		err = extract_rgb(file, file->ceiling_rgb, splited[1]);
	else if (ft_strcmp(splited[0], "F") == 0)
		err = extract_rgb(file, file->floor_rgb, splited[1]);
	return (err);
}

static void	extract_angle(t_player *player, int c)
{
	if (c == 'N')
		player->angle = (3 * PI) / 2;
	else if (c == 'S')
		player->angle = PI / 2;
	else if (c == 'E')
		player->angle = 0;
	else if (c == 'W')
		player->angle = PI;
}

void	extract_player_position(t_cube *file, int y, int x, char c)
{
	file->player.position.y = y * PX + ((PX + 1) / 2);
	file->player.position.x = x * PX + ((PX + 1) / 2);
	if (c == 'N')
	{
		file->player.direction.y = -1;
		file->player.direction.x = 0;
	}
	else if (c == 'S')
	{
		file->player.direction.y = 1;
		file->player.direction.x = 0;
	}
	else if (c == 'E')
	{
		file->player.direction.y = 0;
		file->player.direction.x = 1;
	}
	else if (c == 'W')
	{
		file->player.direction.y = 0;
		file->player.direction.x = -1;
	}
	extract_angle(&file->player, c);
}
