/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:15:35 by amak              #+#    #+#             */
/*   Updated: 2024/03/09 17:44:00 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*ft_strjoin_gnl(char *line, char *buffer)
{
	size_t	line_len;
	size_t	buffer_len;
	char	*output;
	int		x;
	int		y;

	if (!buffer)
		return (NULL);
	line_len = ft_strlen_gnl(line);
	buffer_len = ft_strlen_gnl(buffer);
	output = malloc((line_len + buffer_len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	x = -1;
	y = -1;
	while (++x < (int)line_len)
		output[x] = line[x];
	while (++y < (int)buffer_len)
	{
		output[x] = buffer[y];
		x++;
	}
	output[x] = '\0';
	free (line);
	return (output);
}

static char	*search_line(int flag, char *buffer, int fd)
{
	char	*line;
	int		x;
	int		y;

	line = NULL;
	while (!flag && (buffer[0] || read(fd, buffer, BUFFER_SIZE)))
	{
		x = 0;
		y = 0;
		line = ft_strjoin_gnl(line, buffer);
		while (buffer[x])
		{
			if (flag)
			{
				buffer[y] = buffer[x];
				y++;
			}
			if (buffer[x] == '\n')
				flag = 1;
			buffer[x] = '\0';
			x++;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			i;

	line = NULL;
	flag = 0;
	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		while (buffer[i])
		{
			buffer[i] = '\0';
			i++;
		}
		return (NULL);
	}
	line = search_line(flag, buffer, fd);
	return (line);
}
