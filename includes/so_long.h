/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:10:47 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/13 22:50:23 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"

# define WALL_IMAGE "./textures/wall70x70.xpm"//"./textures/floor70x70.xpm"
# define FLOOR_IMAGE "./textures/floor70x70_1.xpm"
# define COLL_IMAGE "./textures/tacos70x70.xpm"
# define EXIT_IMAGE "./textures/bed70x70.xpm"
# define PLAYER_IMAGE "./textures/player_hack70x70_1.xpm"

# define SCREEN_SIZE_X 1000
# define SCREEN_SIZE_Y 1000
# define COLLUMN_SIZE 50
# define PI 3.14159265359
# define MINI_MAP_DIV_X 5
# define MINI_MAP_DIV_Y 10
# define FOV 60
# define ONE_DEGREE 0.01745329
# define WALL_HEIGHT 1000

# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3

# define SKY_COLOR 0x87CEEB
# define FLOOR_COLOR 0x8B4513

# define MS 40
# define TILE_SIZE 70

# define X_TO_I mlx_xpm_file_to_image

typedef struct s_imgs
{
	t_img	*wall_img;
	t_img	*floor_img;
	t_img	*collectible_img;
	t_img	*exit_img;
	t_img	*player_img;
}	t_imgs;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	dir;
	int		up;
	int		down;
	int		left;
	int		rigth;
	int		rotate_left;
	int		rotate_right;
}	t_player;

typedef struct s_ray_tools
{
	t_player	ray_player;
	double		ray_dir;
	int			wall_height;
	int			wall_start;
	int			wall_end;
	double		ray_increment;
	int			x;
}	t_ray_tools;

typedef struct s_xy
{
	double	x;
	double	y;
}	t_xy;

typedef struct s_ray
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	y_offset;
	double	angle;
	double	side;
	double	distance;
	double	orientation;
}	t_ray;

typedef struct s_int_xy
{
	int	x;
	int	y;
}	t_int_xy;

typedef struct s_map
{
	char	**original_map;
	size_t	map_size_x;
	size_t	map_size_y;
}	t_map;

typedef struct s_master
{
	char		*given_map;
	size_t		collectibles;
	t_map		map;
	t_player	player;
	t_imgs		imgs;
	void		*mlx;
	void		*win;
	void		*canvas;
	void		*mini_map;
	int			mini_map_size_x;
	int			mini_map_size_y;
	int			mini_map_step_size_x;
	int			mini_map_step_size_y;

	t_ray_tools	ray_tools;
	t_ray		ray;
	int			wall_height;

	t_ray		list_of_rays[SCREEN_SIZE_X];

}	t_master;

/*
 * Fonctions int file 1_given_file_tests
 * is_the_file_valid.c : check if the string given as argument is a .ber file
 * 							try to open it, if it fails, exit the program
*/
void	perform_file_tests(t_master *master);
void	is_the_file_valid(t_master *master);
size_t	str_len(const char *s);
void	is_closed(t_master *master, char **map);
void	valid_objects_check(t_master *master, char **map);
void	is_solvable(t_master *master);

/*
 * Fonctions in file error_general_hendler
 */
void	basic_error_handler(t_master *master, int error_code);
void	second_class_error_handler(t_master *master, int error_code);
void	third_class_error_handler(t_master *master, int error_code);
void	fourth_class_error_handler(t_master *master, int error_code);
void	fifth_class_error_handler(t_master *master, int error_code);
void	free_images(t_master *master);

/*
 * Fonctions in file general_purpose_functions
*/

void	map_stock_master(t_master *master);
void	free_map(char **map, size_t y_index);
void	init_master_struct(t_master *master);
void	ft_bzero(void *s, size_t n);

/*
* Fonctions in file 2_mlx_launch
*/

void	load_images(t_master *master);
void	launch_images(t_master *master);

/*
* Fonctions in file 3_mlx_launch
*/

void	end_of_program(t_master *master, int exit_code);
void	launch_window(t_master *master);
int		draw_map(t_master *master);
int		draw_player(t_master *master);

/*
* Fonctions in file 4_event_handling
*/

int		keypress(int keypressed, t_master *master);
int		keyrelease(int keypressed, t_master *master);

int		character_mouvement(t_master *master);

/*
* draw funtions
*/
void	draw_pixel(t_img *canvas, int x, int y, int color);
void	draw_image(t_img *canvas, t_img *img, int x, int y);
void	draw_cross(t_img *canvas, double x, double y, int color);
void	clear_canvas(int size_x, int size_y, t_img *canvas);
void	draw_block(t_master *master, t_img *canvas, t_xy origin, t_img *img);

void	draw_column(t_master *master, \
					t_img *img, t_int_xy origin, t_int_xy dest);
void	draw_sky(t_img *canvas);
void	draw_floor(t_img *canvas);

t_ray	raycast_y(t_master *master, t_player player);
t_ray	raycast_x(t_master *master, t_player player);
double	closest_distance(t_master *master, t_ray hit_x, \
							t_ray hit_y, t_player player);
void	draw_mini_player(t_master *master, t_xy origin);

void	render_3d_map(t_master *master, t_player player);
void	draw_wall(t_master *master, int x);
void	init_tools(t_player *ray_player, t_player *player);

// FOR TESTING PURPOSES ONLY
void	print_map(char **map, size_t y_index);

#endif
