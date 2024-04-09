/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:07:28 by facu              #+#    #+#             */
/*   Updated: 2024/04/09 21:07:30 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	handle_line(t_cube *file, char *line)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (split_line && split_line[0])
	{
		if (extract_metadata(file, split_line))
		{
			free_str_arr(split_line);
			free(line);
			exit_error(NULL, file);
		}
	}
	free_str_arr(split_line);
	free(line);
}

static void	parse_metadata(t_cube *file, char ***content)
{
	char	*line;

	while (*content && **content && !text_rgb_ok(file))
	{
		ft_putspace(**content);
		line = ft_strtrim(**content, " \t\v\f\r\n");
		if (line && *line)
		{
			handle_line(file, line);
		}
		(*content)++;
	}
}

static void	skip_empty_lines(char ***content)
{
	while (*content && **content && ft_noprintchar(**content))
		(*content)++;
}

void	parse_values(t_cube *file, char **content)
{
	parse_metadata(file, &content);
	skip_empty_lines(&content);
	if (content && *content)
		parse_map(file, content);
}
