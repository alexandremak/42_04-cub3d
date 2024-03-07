/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:30:51 by amak              #+#    #+#             */
/*   Updated: 2024/03/06 23:54:49 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_trimstr(char *str)
{
	int		end;
	int		begin;
	int		i;
	char	*output;

	begin = 0;
	end = (int)ft_strlen(str) - 1;
	i = 0;
	while (ft_isspace(str[begin]))
		begin++;
	while (ft_isspace(str[end]))
		end--;
	if (begin > end)
		return (NULL);
	output = (char *)malloc(((end - begin) + 2) * sizeof(char));
	if (!output)
		return (NULL);
	while (begin <= end)
		output[i++] = str[begin++];
	output[i] = '\0';
	return (output);
}
