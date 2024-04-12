# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 19:20:14 by amak              #+#    #+#              #
#    Updated: 2024/04/11 18:02:09 by ftroiter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc -g

UTILS_DIR = ./utils/

MINILIBX_DIR = ./minilibx-linux/

CFLAGS = -Wall -Werror -Wextra -o3

LFLAGS = -Lminilibx-linux -I./utils/inc/ -I./minilibx-linux -L/usr/lib -lmlx -lXext -lX11 -lm -lz -L./utils

UTILS = $(UTILS_DIR)utils.a

INC = -I ./inc/

SRC_PATH = ./src/

OBJ_PATH = ./obj/

SRC_FILES = render.c \
			2d_map.c \
			3d_map.c \
			check_content.c \
			check_map.c \
			check_map2.c \
			check_file.c \
			dda_utils.c \
			debug.c \
			events.c \
			free.c \
			exit.c \
			load_file.c \
			parse_map.c \
			parse_metadata.c \
			parse_metadata_utils.c \
			main.c \
			init_mlx.c \
			movement.c \
			parse.c \
			raycast.c \
			textures.c \
						
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(LFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ) inc/cub3D.h
	make -C $(UTILS_DIR)
	make -C $(MINILIBX_DIR) > /dev/null 2>&1
	$(CC) $(CFLAGS) $(OBJ) $(UTILS) $(LFLAGS) -o $(NAME)
	@echo [CUB3D] :: Object files created!
	@echo [CUB3D] :: Executable file created!

clean:
	rm -rf $(OBJ_PATH)
	make -C $(UTILS_DIR) clean > /dev/null 2>&1
	make -C $(MINILIBX_DIR) clean
	@echo [CUB3D] :: Deleted objected files!

fclean: clean
	rm -f $(NAME)
	make -C $(UTILS_DIR) fclean
	@echo [CUB3D] :: Deleted executable!
	
re: fclean all

rs: all
	./$(NAME) maps/valid/example.cub
.PHONY: all clean fclean re
