# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amak <amak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 19:20:14 by amak              #+#    #+#              #
#    Updated: 2024/02/20 19:25:15 by amak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc -g

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -Lminilibx-linux -I/minilibx-linux/mlx.h -L/usr/lib -lmlx -lXext -lX11 -lm -lz

INC = -I ./inc/

SRC_PATH = src/

OBJ_PATH = obj/

SRC_FILES = main.c 
			
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo Object files created!
	@echo Executable file created!

clean:
	@rm -rf $(OBJ_PATH)
	@echo Deleted objected files!

fclean: clean
	@rm -f $(NAME)
	@echo Deleted executable!
	
re: fclean all

.PHONY: all clean fclean re
