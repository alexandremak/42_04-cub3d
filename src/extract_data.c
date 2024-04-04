/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:00:21 by amak              #+#    #+#             */
/*   Updated: 2024/04/04 22:33:52 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	extract_txtr(t_file *file, char **texture, char *pathstr)
{
	int	fd;

	fd = open(pathstr, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		exit_error("Scene description: wall texture file not found",
			file);
	}
	if (texture && *texture)
		exit_error("Scene description: duplicate wall texture \
			identifier", file);
	*texture = ft_strdup(pathstr);
	close(fd);
}

static void	extract_rgb(t_file *file, int *rgb, char *splited)
{
	char	**numbers;
	int		i;

	i = -1;
	if (rgb[3])
		exit_error("Scene description: duplicate RGB values", file);
	if (!splited)
		exit_error("Scene description: no RGB values", file);
	numbers = ft_split(splited, ',');
	if (ft_strarr_size(numbers) > 3)
	{
		free_str_arr(numbers);
		exit_error("Scene description: invalid RGB values", file);
	}
	while (*numbers && numbers[++i])
	{
		if (ft_strlen(numbers[i]) > 4 || !ft_isdigit_str(numbers[i]))
		{
			free_str_arr(numbers);
			exit_error("Scene description: invalid RGB values", file);
		}
		rgb[i] = ft_atoi(numbers[i]);
	}
	free_str_arr(numbers);
	if (i < 3)
		exit_error("Scene description: insuficient RGB values", file);
	rgb[3] = 1;
}

void	extract_metadata(t_file *file, char **splited)
{
	if (ft_strcmp(splited[0], "NO") == 0)
		extract_txtr(file, &file->no, splited[1]);
	else if (ft_strcmp(splited[0], "SO") == 0)
		extract_txtr(file, &file->so, splited[1]);
	else if (ft_strcmp(splited[0], "WE") == 0)
		extract_txtr(file, &file->we, splited[1]);
	else if (ft_strcmp(splited[0], "EA") == 0)
		extract_txtr(file, &file->ea, splited[1]);
	else if (ft_strcmp(splited[0], "C") == 0)
		extract_rgb(file, file->ceiling_rgb, splited[1]);
	else if (ft_strcmp(splited[0], "F") == 0)
		extract_rgb(file, file->floor_rgb, splited[1]);
}

static void	calc_angle(t_player *player, int c)
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

void	extract_player_position(t_file *file, int y, int x, char c)
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
	calc_angle(&file->player, c);
}
