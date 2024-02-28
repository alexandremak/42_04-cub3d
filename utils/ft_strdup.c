/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:32:54 by amak              #+#    #+#             */
/*   Updated: 2024/02/27 20:33:16 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s)
{
	int		lenth;
	int		pos;
	char	*pnt;

	lenth = ft_strlen((char *)s);
	pnt = (char *)malloc(lenth + 1);
	if (pnt == NULL)
		return (NULL);
	pos = 0;
	while (s[pos] != '\0')
	{
		pnt[pos] = s[pos];
		pos++;
	}
	pnt[pos] = '\0';
	return (pnt);
}
