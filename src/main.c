/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:30:11 by amak              #+#    #+#             */
/*   Updated: 2024/02/28 23:41:48 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int main(int argc, char **argv)
{
    static t_file cub_file;
    
    parsing(argc, argv, &cub_file);
    exit_game(NORMAL, &cub_file);
}
