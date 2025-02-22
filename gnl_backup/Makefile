# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 06:30:39 by hikarimac         #+#    #+#              #
#    Updated: 2025/02/03 22:54:11 by hshinaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

ifdef BUFFER_SIZE
    CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)
else
    CFLAGS += -D BUFFER_SIZE=42
endif

NAME = get_next_line.a
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re