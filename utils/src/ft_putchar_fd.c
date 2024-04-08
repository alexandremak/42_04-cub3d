/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:20:14 by ftroiter          #+#    #+#             */
/*   Updated: 2024/04/08 18:22:29 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

// Outputs the character ’c’ to the given file descriptor.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
