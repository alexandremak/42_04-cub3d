/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:21:57 by amak              #+#    #+#             */
/*   Updated: 2024/03/20 22:52:31 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

char	*ft_strchr(const char *s, int c)
{
	int		pos;
	char	*str;

	pos = 0;
	str = (char *)s;
	while (str[pos])
	{
		if (str[pos] == (unsigned char)c)
			return (&str[pos]);
		pos++;
	}
	if (str[pos] == (char)c)
		return (&str[pos]);
	return (NULL);
}
