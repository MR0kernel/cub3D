# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 19:59:30 by guilrodr          #+#    #+#              #
#    Updated: 2024/06/19 20:09:18 by guilrodr         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -g3#-Werror
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
UTILSFLAGS = -L./ft_printf -l:libftprintf.a
RM = rm -f

SRC =	so_long.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		general_purpose_functions/size_and_search.c \
		general_purpose_functions/map_stock.c \
		1_given_file_tests/1_file_tests_master.c \
		1_given_file_tests/ends_with_ber.c \
		1_given_file_tests/is_closed.c \
		1_given_file_tests/objects_are_valid.c \
		1_given_file_tests/is_solvable.c \
		2_try_load_images/1_images_master.c \
		2_try_load_images/images_converter.c \
		2_try_load_images/init_master_structs.c \
		3_mlx_window_launch/1_window_master.c \
		3_mlx_window_launch/draw_master.c \
		3_mlx_window_launch/stop_program.c \
		3_mlx_window_launch/raycaster.c \
		4_event_handling/1_mouvement_master.c \
		4_event_handling/key_press.c \
		error_general_hendler/error_general_hendler.c \
		error_general_hendler/free.c \
		error_general_hendler/free_images.c \
		draw_funtions/draw_by_pixel.c

all: $(NAME)


$(NAME): $(SRC) includes/so_long.h
	make -C ft_printf
	make -C mlx_linux
	$(CC) $(CFLAGS) $(SRC) $(MLXFLAGS) $(UTILSFLAGS) -o $(NAME)

clean:
	make clean -C ft_printf
	make clean -C mlx_linux
	$(RM) $(NAME)

fclean: clean
	make fclean -C ft_printf
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


