/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:54:31 by amak              #+#    #+#             */
/*   Updated: 2024/04/07 22:21:34 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../utils/inc/utils.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

/* MATH CONST */
# define PI 3.14159265
# define YAXIS 0
# define XAXIS 1
# define TOLERANCE 0.00001

/* KEYBOARD CODES */
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define LA 65361
# define RA 65363

/* SIZE OF WINDOW AND EACH TILE */
# define PX 31
# define PACE 5
# define PIDIVUNITS 18
# define PLYLEN 9
# define UANGLE 3.141592 / 360

/* WALLS COLLISION VALUES*/
enum wall_direction {
	NONE,
	NORTH,
	SOUTH,
	EAST,
	WEST
};

/* STRUCTURES */
typedef struct s_vector
{
	float		x;
	float		y;
}				t_vector;

typedef struct s_player
{
	t_vector	position;
	t_vector	direction;
	float		angle;
}				t_player;

typedef struct s_ray
{
	int			y;
	int			x;
	int			distance_y;
	int			distance_x;
	t_vector	direction;
	float		angle;
	float		length;
	int			hit_vert_wall;
	int			wall_texture;
	int			wall_hit;
}	t_ray;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_windows
{
	void		*mlx;
	void		*win;
	t_image		image;
}				t_windows;

typedef struct s_file
{
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
	int			columns;
	t_player	player;
	t_windows	graphic;
}				t_file;

/* EXIT FUNCTIONS */
void	exit_error(char *message, t_file *file);
void	exit_game(t_file *file);
void	free_str_arr(char **arr);
void	free_all(t_file *file);

/* CHECK AND LOAD FUNCTIONS */
void	check_file(int argc, char **argv, t_file *file);
void	read_content(t_file *file);

/* EXTRACT DATA FUNCTIONS */
void	extract_metadata(t_file *file, char **splited);
void	extract_player_position(t_file *file, int y, int x, char c);

/* EXTRACT MAP FUNCTIONS */
void	load_map(t_file *file, char **mtrx);

/* CHECK FILE CONTENT */
void	check_content(t_file *file);

/* CHECK MAP */
void	check_map(t_file *file, char **map);

/* MLX FUNCTIONS*/
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	put_pixel_to_image(t_image *image_data, int x, int y, int color);
void	init_mlx(t_file *file);
int		key_press(int keycode, t_file *file);

/* BUILD MAP FUNCTIONS*/
void	draw_map(t_file *file, t_windows *graphic);

/* MOVEMENT FUNCTIONS */
int		check_wall(int posy, int posx, char **map);
void	move(t_player *player, int keycode, char **map);

/* DDA UTILS FUNCTIONS*/
int		distance_y(int y, float angle);
int		distance_x(int x, float angle);
float	get_x_step(int adj, float angle);
float	get_y_step(int opose, float angle);
void	increment_ray_length(t_ray *ray, float step_y, float step_x);

/* RAYCASTING */
void	draw_ray(t_image *image, t_player *player, t_file *file, float angle);

#endif
