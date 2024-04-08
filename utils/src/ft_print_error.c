/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:31:01 by ftroiter          #+#    #+#             */
/*   Updated: 2024/04/08 17:34:17 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	ft_print_error(int n, ...)
{
	va_list	args;

	va_start(args, n);
	ft_putstr_fd("👀", STDERR_FILENO);
	while (n--)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(va_arg(args, char *), STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	va_end(args);
}