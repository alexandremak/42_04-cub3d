/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:54:31 by amak              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/08 20:51:02 by ftroiter         ###   ########.fr       */
=======
/*   Updated: 2024/04/08 21:03:42 by amak             ###   ########.fr       */
>>>>>>> 1889a72505466fe31cdfde68cffb2ac27803908b
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
# define PX 64
# define PACE 5
# define PIDIVUNITS 18
# define PLYLEN 9
# define UANGLE 3.141592 / 360
# define FOV			1.047198
# define HALF_FOV		0.523599
# define PLANE_DIST		960
# define SCREEN_WIDTH	1024
# define SCREEN_HEIGHT  768

# define MAX_TEXTURES 4

/* WALLS COLLISION VALUES*/
enum wall_direction {
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NONE
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

typedef struct s_texture
{
	t_image		image;
	int			width;
	int			height;
}				t_texture;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	t_image		image;
}				t_window;

typedef struct s_file
{
	char		*filepath;
	int			fd;
	char		**content;
	char		*texture_paths[4];
	int			floor_rgb[4];
	int			ceiling_rgb[4];
	char		**map;
	int			rows;
	int			columns;
	t_player	player;
	t_window	graphic;
	t_texture	textures[4];
	t_ray		rays[SCREEN_WIDTH];
}				t_file;

/* EXIT FUNCTIONS */
void	exit_error(char *message, t_file *file);
void	exit_game(t_file *file);
void	free_str_arr(char **arr);
void	free_all(t_file *file);

/* CHECK AND LOAD FUNCTIONS */
void	check_file(int argc, char **argv, t_file *file);
void	read_scene_file(t_file *file);
int		texture_paths_ok(t_file *file);
void	parse_values(t_file *file, char **content);
int		texture_paths_ok(t_file *file);
int		text_rgb_ok(t_file *file);

/* EXTRACT DATA FUNCTIONS */
int		extract_metadata(t_file *file, char **splited);
void	extract_player_position(t_file *file, int y, int x, char c);

/* EXTRACT MAP FUNCTIONS */
void	get_map(t_file *file, char **mtrx);

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
void	draw_map(t_file *file, t_window *graphic);
void	put_square(t_image *image, int x, int y, int color, int out_color);

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
void	castray(t_ray *ray, t_player *player, t_file *file, float angle);
void	raycasting(t_file *file, t_ray *rays);
void	render_cicle(t_file *file);
void	draw_walls(t_file *file, t_ray *rays);

/* TEXTURES */
void	load_textures(t_file *cube);
int		get_texture_color(t_file *file, int y, int offset_x, t_ray ray, int wall_height);

#endif
