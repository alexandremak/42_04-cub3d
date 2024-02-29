/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:25:24 by amak              #+#    #+#             */
/*   Updated: 2024/02/28 21:42:27 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int     ft_isspace(char c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_trimstr(char * str);
char	*get_next_line(int fd);

#endif
