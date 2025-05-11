NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Iincludes

SRC_DIR = src
SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/error/error_input_check.c \
	$(SRC_DIR)/error/error_conversion.c \
      $(SRC_DIR)/init/init_stack.c \
      $(SRC_DIR)/stack/stack_utilities.c \
      $(SRC_DIR)/sort/sort_small.c \
      $(SRC_DIR)/sort/sort_large.c \
      $(SRC_DIR)/sort/sort_chunk_utils.c \
	$(SRC_DIR)/sort/sort_index_utils.c \
      $(SRC_DIR)/operations/core_ops.c \
      $(SRC_DIR)/operations/op_swap.c \
      $(SRC_DIR)/operations/op_push.c \
      $(SRC_DIR)/operations/op_rotate.c \
      $(SRC_DIR)/operations/op_reverse_rotate.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


# ********** テスト用 **********

TEST_NAME := test_main
TEST_SRC  := $(SRC_DIR)/test_main.c
TEST_OBJ  := $(TEST_SRC:.c=.o)

# push_swap の OBJ から main.o だけ除去
OBJ_NO_MAIN := $(filter-out $(SRC_DIR)/main.o,$(OBJ))

tests: $(NAME) $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ) $(OBJ_NO_MAIN)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

clean-tests:
	rm -f $(TEST_OBJ) $(TEST_NAME)

.PHONY: tests clean-tests