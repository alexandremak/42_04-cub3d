# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amak <amak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 22:18:14 by amak              #+#    #+#              #
#    Updated: 2024/03/09 18:07:21 by amak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = utils.a

CC = @cc -g

CFLAGS = -Wall -Wextra -Werror

INC = -I ./inc/

SRC_PATH = ./src/

OBJ_PATH = ./obj/

SRC_FILES =	ft_atoi.c \
			ft_calloc.c \
			ft_isspace.c \
			ft_mtrxdup.c \
			ft_putspace.c \
			ft_split.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strtrim.c \
			get_next_line.c

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))		

OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo [UTILS] :: Object files created!
	@echo [UTILS] :: Archive file created!
	
clean:
	@rm -rf $(OBJ_PATH)
	@echo [UTILS] :: Object files deleted!

fclean: clean
	@rm -f $(NAME)
	@echo [UTILS] :: Archive file deleted!

re: fclean all

.PHONY: all bonus clean fclean re