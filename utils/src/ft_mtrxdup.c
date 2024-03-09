/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrxdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:02:24 by amak              #+#    #+#             */
/*   Updated: 2024/03/09 18:05:25 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

char	**ft_mtrxdup(char **mtrx)
{
	int		i;
	int		size;
	char	**res;

	i = 0;
	size = 0;
	if (!mtrx && *mtrx[0])
		return (NULL);
	while (mtrx[size])
		size++;
	res = ft_calloc((size + 1), sizeof(char *));
	while (res[i])
	{
		res[i] = ft_strdup(mtrx[i]);
		i++;
	}
	return (res);
}
