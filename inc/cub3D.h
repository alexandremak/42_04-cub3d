/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:54:31 by amak              #+#    #+#             */
/*   Updated: 2024/03/09 18:19:59 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//	# include "minilibx-linux/mlx.h"
# include "../utils/inc/utils.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

/* KEYBOARD CODES*/
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100

/* SIZE OF WINDOW AND EACH TILE*/
# define PX 64

/* EXIT ERROR CODES */
typedef enum e_exit_code
{
	NORMAL,
	ARGC_ERROR,
	BLANK_FPATH,
	EXT_ERROR,
	NO_FILE,
	W_CONTENT,
	NOALL_TEXTURES,
	RGB_IRANGE,
	MAP_NCLOSED,
	INVALID_CONTENT
}	t_exit_code;

/* STRUCTURES */
typedef struct s_vector {
	int		x;
	int		y;
}	t_vector;

typedef struct s_file {
	char	*filepath;
	int		fd;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	char	**map;
}	t_file;

typedef struct s_player {
	t_vector	position;
	t_vector	direction;
}	t_player;

void	exit_game(t_exit_code exit_code, t_file *file);

void	free_mtrx(char **mtrx);
void	free_all(t_file *file);

/* PARSING AND READ FUNCTIONS */
void	check_file(int argc, char **argv, t_file *file);
void	read_content(t_file *file);

#endif
