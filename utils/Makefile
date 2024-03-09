# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amak <amak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 22:18:14 by amak              #+#    #+#              #
#    Updated: 2024/03/09 00:12:16 by amak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = utils.a

CC = @cc -g

CFLAGS = -Wall -Wextra -Werror

SOURCES = 	ft_atoi.c \
			ft_calloc.c \
			ft_isspace.c \
			ft_putspace.c \
			ft_split.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_trimstr.c \
			get_next_line.c
			
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	@echo [UTILS] :: Object files created!
	@echo [UTILS] :: Archive file created!
	
clean:
	@rm -f $(OBJECTS)
	@echo [UTILS] :: Object files deleted!

fclean: clean
	@rm -f $(NAME)
	@echo [UTILS] :: Archive file deleted!

re: fclean all

.PHONY: all bonus clean fclean re