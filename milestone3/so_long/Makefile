# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 18:44:08 by hikarimac         #+#    #+#              #
#    Updated: 2025/07/22 19:09:45 by hikarimac        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = src/main.c src/map_parser.c src/game.c src/utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all