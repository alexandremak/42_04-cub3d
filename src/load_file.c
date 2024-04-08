/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:43:54 by amak              #+#    #+#             */
/*   Updated: 2024/04/08 00:58:19 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	load_content(t_file *file, int fd, int count_line)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		load_content(file, fd, count_line + 1);
	else if (count_line > 0)
		file->content = malloc(sizeof(char *) * (count_line + 1));
	if (file->content)
		file->content[count_line] = line;
}


int	texture_paths_ok(t_file *file)
{
    int	i;

    i = 0;
    while (i < MAX_TEXTURES && file->texture_paths[i])
        i++;
    return (i == MAX_TEXTURES);
}

int	text_rgb_ok(t_file *file)
{
	int	res;

	res = 0;
	if (texture_paths_ok(file) && file->ceiling_rgb[3] && file->floor_rgb[3])
		res = 1;
	return (res);
}

static void	parse_values(t_file *file, char **content)
{
	char	*line;
	char	**split_line;

	while (content && *content && !text_rgb_ok(file))
	{
		ft_putspace(*content);
		line = ft_strtrim(*content, " \t\v\f\r\n");
		if (line && *line) 
		{
			split_line = ft_split(line, ' ');
			if (split_line && split_line[0])
				extract_metadata(file, split_line);
			free_str_arr(split_line);
			free (line);
		}
		content++;
	}
	while (content && *content && ft_noprintchar(*content))
		content++;
	if (content && *content)
		load_map(file, content);
}

void	read_scene_file(t_file *file)
{
	load_content(file, file->fd, 0);
	if (!file->content)
		exit_error("Scene description file without content!", file);
	parse_values(file, file->content);
}
