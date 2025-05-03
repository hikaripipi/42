LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/error_handling.c \
	  $(SRC_DIR)/stack_operations.c \
	  $(SRC_DIR)/stack_utilities.c  \
	  $(SRC_DIR)/sorting_algorithms.c
	  

OBJ = $(SRC:.c=.o)

INCLUDE = -Iincludes

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

