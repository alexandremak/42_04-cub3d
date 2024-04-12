/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:54:31 by amak              #+#    #+#             */
/*   Updated: 2024/04/11 18:24:52 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

# include "mlx.h"
# include "utils.h"

/* MATH CONST */
# define PI 3.14159265
# define YAXIS 0
# define XAXIS 1

/* KEYBOARD CODES */
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define LA 65361
# define RA 65363
# define M 109

/* SIZE OF WINDOW AND EACH TILE */
# define PX 200
# define PACE 10
# define TURNANGLE 0.1
# define PLYLEN 9
# define FOV			1.047198 // 60 deg in rad
# define HALF_FOV		0.523599 // 30 deg in rad
# define PLANE_DIST		652.719 // Hard codede :P
# define SCREEN_WIDTH	680
# define SCREEN_HEIGHT 	480

/* STRUCT VALUES */
# define MAX_TEXTURES 4

/* COLORS */
# define RED			0x00ff0000
# define LIGHT_GREY		0x00dfdfdf
# define BLACK			0x00000000

# define X 0
# define Y 1
# define TOLERANCE 0.00001 // res + 0.00001

/* WALLS COLLISION VALUES*/
enum e_wall_direction {
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NONE // WHAT ? Weird
};

/* STRUCTURES */
typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_player
{
	t_vector	position;
	t_vector	direction;
	double		angle;
}				t_player;

typedef struct s_ray
{
	double			y;
	double			x;
	double			distance_y;
	double			distance_x;
	t_vector		direction;
	t_vector		origin;
	bool				is_north;
	bool				is_east;
	double			angle;
	double			length;
	int				hit_vert_wall; // Boolean if 1 hit vert else hit horz
	int				wall_texture; // Texture to hit...
	double			wall_hit; // KEY Point!
	int				wall_height;
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

typedef struct s_cube
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
	int			show_minimap;
	int			map_scale;
	t_texture	textures[4];
	t_ray		*rays;
	int 		redline;
}				t_cube;

/* EXIT  */
void	exit_error(char *message, t_cube *file);
void	exit_game(t_cube *file);
void	free_str_arr(char **arr);
void	free_all(t_cube *file);

/* VALIDATION  */
void	read_scene_file(t_cube *file);
void	check_file(int argc, char **argv, t_cube *file);
int		texture_paths_ok(t_cube *file);
int		texture_paths_ok(t_cube *file);
int		text_rgb_ok(t_cube *file);
void	check_content(t_cube *file);
void	check_map(t_cube *file, char **map);

/* PARSE DATA  */
int		extract_metadata(t_cube *file, char **splited);
void	parse_values(t_cube *file, char **content);
void	extract_player_position(t_cube *file, int y, int x, char c);
void	parse_map(t_cube *file, char **mtrx);
int		is_valid_rgb(char *number);
int		process_numbers(char **numbers, int *rgb);

/* MLX */
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	put_pixel_to_image(t_image *image_data, int x, int y, int color);
void	init_mlx(t_cube *file);
int		key_press(int keycode, t_cube *file);

/* 2D RENDER */
void	draw_minimap(t_cube *file, t_window *graphic);

/* 3D RENDER */
void	draw_floor_and_ceiling(t_cube *cube);
void	draw_walls(t_cube *file, t_ray *rays);

/* EVENTS */
int		key_press(int keycode, t_cube *file);

/* MOVEMENT  */
int		check_wall(double posy, double posx, t_cube *cube);
void	move(t_player *player, int keycode, t_cube *cube);

/* DDA UTILS */
double	distance_y(double y, double direction_y, bool is_north);
double	distance_x(double x, double direction_x, bool is_east);
double	get_x_step(int adj, double angle);
double	get_y_step(int opose, double angle);
void	increment_ray_length(t_ray *ray, double step_y, double step_x);

/* RAYCASTING */
void	draw_ray(t_image *image, t_player *player, t_cube *file, double angle);
void	castray(t_ray *ray, t_player *player, t_cube *file, double angle);
void	raycasting(t_cube *file, t_ray *rays);
void	render_scene(t_cube *file);
void	draw_walls(t_cube *file, t_ray *rays);

/* TEXTURES */
void	load_textures(t_cube *cube);
int		get_texture_color(t_cube *file, int y, int offset_x, t_ray ray);

void	print_content(t_cube cube, int is_bool);
void	check_inside(t_cube *file, char **map);

#endif
