# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 19:27:45 by hshinaga          #+#    #+#              #
#    Updated: 2024/11/12 22:10:04 by hshinaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
       ft_printf_utils.c \
       ft_putnbr_base.c \
       ft_putptr.c

OBJS = $(SRCS:.c=.o)

# libft関連
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re