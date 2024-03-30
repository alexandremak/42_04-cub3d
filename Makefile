# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amak <amak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 19:20:14 by amak              #+#    #+#              #
#    Updated: 2024/03/29 21:08:04 by amak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc -g

UTILS_DIR = ./utils/

MINILIBX_DIR = ./minilibx-linux/

CFLAGS = #-Wall -Wextra -Werror -O3

LFLAGS = -Lminilibx-linux -I/minilibx-linux/mlx.h -L/usr/lib -lmlx -lXext -lX11 -lm -lz

UTILS = $(UTILS_DIR)utils.a

INC = -I ./inc/

SRC_PATH = ./src/

OBJ_PATH = ./obj/

SRC_FILES = main.c \
			free.c \
			exit.c \
			check_file.c \
			load_file.c \
			extract_data.c \
			load_map.c \
			check_content.c \
			check_map.c \
			init_mlx.c \
			build_map.c \
			movement.c
						
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

.PHONY: all clean fclean re
