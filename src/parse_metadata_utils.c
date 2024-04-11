/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_metadata_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:47:23 by facu              #+#    #+#             */
/*   Updated: 2024/04/11 15:36:12 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	is_valid_rgb(char *number)
{
	return (ft_strlen(number) <= 4 && ft_isdigit_str(number));
}

int	process_numbers(char **numbers, int *rgb)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < 3 && numbers[i])
	{
		if (!is_valid_rgb(numbers[i]))
		{
			error = 1;
			break ;
		}
		rgb[i] = ft_atoi(numbers[i]);
		i++;
	}
	while (i < 3)
	{
		error = 1;
		i++;
	}
	if (!error)
		rgb[3] = 1;
	return (error);
}
