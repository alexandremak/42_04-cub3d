/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:11:19 by amak              #+#    #+#             */
/*   Updated: 2024/03/09 17:53:42 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	ft_atoi(const char *nptr)
{
	int	pos;
	int	sign;
	int	res;

	pos = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(nptr[pos]))
		pos++;
	if (nptr[pos] == '-' || nptr[pos] == '+')
	{
		if (nptr[pos] == '-' )
			sign = -1;
		pos++;
	}
	while (nptr[pos] >= '0' && nptr[pos] <= '9')
	{
		res = (res * 10) + (nptr[pos] - 48);
		pos++;
	}
	res = res * sign;
	return (res);
}
