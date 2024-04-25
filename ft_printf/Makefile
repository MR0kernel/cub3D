# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilrodr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 16:46:15 by guilrodr          #+#    #+#              #
#    Updated: 2023/10/15 16:46:27 by guilrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  	ft_printf.c \
		ft_args_control.c \
		usefull.c	\
		minilib/ft_base.c \
		minilib/ft_putchar_fd.c \
		minilib/ft_putnbr_fd.c \
		minilib/ft_putstr_fd.c \

OBJ_DIRECTORY = ./.obj/
CC = cc
FLAGS = -c -Wall -Wextra -Werror -g
OBJS = $(addprefix $(OBJ_DIRECTORY), $(SRCS:.c=.o))

$(NAME): $(OBJ_DIRECTORY) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIRECTORY)%.o: %.c Makefile ft_printf.h
	$(CC) $(FLAGS) $< -o $@

$(OBJ_DIRECTORY):
	mkdir -p $(OBJ_DIRECTORY) $(OBJ_DIRECTORY)minilib $(OBJ_DIRECTORY)printers

all : $(NAME)

clean :
	$(RM) $(NAME)
	rm -rf $(OBJ_DIRECTORY)

fclean : clean
	rm -rf $(NAME)

re : fclean all
