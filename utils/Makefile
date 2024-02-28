# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amak <amak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 22:18:14 by amak              #+#    #+#              #
#    Updated: 2024/02/27 23:43:06 by amak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = utils.a

CC = @cc -g

CFLAGS = -Wall -Wextra -Werror

SOURCES = 	ft_strdup.c \
			ft_strlen.c \
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