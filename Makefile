# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 19:20:14 by amak              #+#    #+#              #
#    Updated: 2024/04/08 17:38:12 by ftroiter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc -g

UTILS_DIR = ./utils/

MINILIBX_DIR = ./minilibx-linux/

CFLAGS = 

LFLAGS = -Lminilibx-linux -I/minilibx-linux/mlx.h -L/usr/lib -lmlx -lXext -lX11 -lm -lz

UTILS = $(UTILS_DIR)utils.a

INC = -I ./inc/

SRC_PATH = ./src/

OBJ_PATH = ./obj/

SRC_FILES = 3d_render.c \
			build_map.c \
			check_content.c \
			check_map.c \
			check_file.c \
			dda_utils.c \
			free.c \
			exit.c \
			extract_data.c \
			load_file.c \
			get_map.c \
			main.c \
			init_mlx.c \
			movement.c \
			raycast.c \
			textures.c \
						
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	@make -C $(UTILS_DIR)
	@make -C $(MINILIBX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(UTILS) $(LFLAGS) -o $(NAME)
	@echo [CUB3D] :: Object files created!
	@echo [CUB3D] :: Executable file created!

clean:
	@rm -rf $(OBJ_PATH)
	@make -C $(UTILS_DIR) clean
	@make -C $(MINILIBX_DIR) clean
	@echo [CUB3D] :: Deleted objected files!

fclean: clean
	@rm -f $(NAME)
	@make -C $(UTILS_DIR) fclean
	@echo [CUB3D] :: Deleted executable!
	
re: fclean all

rs: all
	./$(NAME) maps/example.cub
.PHONY: all clean fclean re
