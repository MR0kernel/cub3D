/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:10:47 by guilrodr          #+#    #+#             */
/*   Updated: 2024/05/10 17:30:24 by guilrodr         ###   ########lyon.fr   */
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

# define WALL_IMAGE "./textures/wall70x70_1.xpm"
# define FLOOR_IMAGE "./textures/floor70x70.xpm"
# define COLL_IMAGE "./textures/tacos70x70.xpm"
# define EXIT_IMAGE "./textures/bed70x70.xpm"
# define PLAYER_IMAGE "./textures/player_hack70x70_1.xpm"

#define SCREEN_SIZE_X 700
#define SCREEN_SIZE_Y 500

# define X_TO_I mlx_xpm_file_to_image

typedef struct s_imgs
{
	void	*wall_img;
	void	*floor_img;
	void	*collectible_img;
	void	*exit_img;
	void	*player_img;
}	t_imgs;

typedef struct s_player
{
	size_t	x;
	size_t	y;
}	t_player;

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
    void        *canvas;
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
void	draw_map(t_master *master);
int		draw_player(t_master *master);

/*
* Fonctions in file 4_event_handling
*/

int		keypress(int keypressed, t_master *master);
int		character_mouvement(t_master *master, int keypressed);

/*
* draw funtions
*/
void    draw_pixel(t_img *canvas, int x, int y, int color);
void    draw_debug_lines(t_img *canvas);

// FOR TESTING PURPOSES ONLY
void	print_map(char **map, size_t y_index);

#endif
