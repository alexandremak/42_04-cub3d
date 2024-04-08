# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 22:18:14 by amak              #+#    #+#              #
#    Updated: 2024/04/08 17:34:01 by ftroiter         ###   ########.fr        #
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
			ft_isdigit_str.c \
			ft_isdigit.c \
			ft_isspace.c \
			ft_mtrxdup.c \
			ft_noprintchar.c \
			ft_print_error.c \
			ft_putchar_fd.c \
			ft_putspace.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strarr_size.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strtrim.c \
			ft_strrchr.c \
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