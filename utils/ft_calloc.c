/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:24:59 by amak              #+#    #+#             */
/*   Updated: 2024/03/05 22:25:11 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pnt;
	size_t	pos;

	pos = 0;
	pnt = (char *)malloc(nmemb * size);
	if (pnt == NULL)
		return (NULL);
	while (pos < (nmemb * size))
	{
		pnt[pos] = '\0';
		pos++;
	}
	return ((void *)pnt);
}
