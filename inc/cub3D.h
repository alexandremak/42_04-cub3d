/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:54:31 by amak              #+#    #+#             */
/*   Updated: 2024/03/25 22:37:28 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../utils/inc/utils.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

/* KEYBOARD CODES */
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100

/* SIZE OF WINDOW AND EACH TILE */
# define PX 32

/* STRUCTURES */
typedef struct s_vector {
	int		x;
	int		y;
}	t_vector;

typedef struct s_player {
	t_vector	position;
	t_vector	direction;
}	t_player;

typedef struct s_windows {
	void	*mlx;
	void	*win;
}	t_windows;

typedef struct s_file {
	char		*filepath;
	int			fd;
	char		**content;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor_rgb[4];
	int			ceiling_rgb[4];
	char		**map;
	int			rows;
	int			collums;
	t_player	player;
	t_windows	graphic;
}	t_file;

void	exit_error(char *message, t_file *file);
void	exit_game(t_file *file);

void	free_mtrx(char **mtrx);
void	free_all(t_file *file);

/* CHECK AND LOAD FUNCTIONS */
void	check_file(int argc, char **argv, t_file *file);
void	read_content(t_file *file);

/* EXTRACT DATA FUNCTIONS */
void	extract_data(t_file *file, char **splited);

/* EXTRACT MAP FUNCTIONS */
void	load_map(t_file *file, char **mtrx);

/* CHECK FILE CONTENT */
void	check_content(t_file *file);

/* CHECK MAP */
void	check_map(t_file *file, char **map);

/* MLX FUNCTIONS*/
void	init_mlx(t_file *file);
int		key_press(int keycode, t_file *file);

#endif
