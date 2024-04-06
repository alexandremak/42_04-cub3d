/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:25:24 by amak              #+#    #+#             */
/*   Updated: 2024/04/04 22:29:58 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isdigit_str(char *str);
int		ft_isdigit(int c);
int		ft_isspace(char c);
char	**ft_mtrxdup(char **mtrx);
int		ft_noprintchar(char *str);
void	ft_putspace(char *str);
char	**ft_split(char const *s, char c);
int		ft_strarr_size(char **arr);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrchr(const char *s, int c);
char	*get_next_line(int fd);

#endif
