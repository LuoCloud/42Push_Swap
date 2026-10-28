NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I./libft

SRCS = push_swap.c \
	algo_small.c \
	algo_simple.c \
	algo_medium.c \
	algo_medium_utils.c \
	algo_chunk_a.c \
	algo_utils.c \
	algo_utils2.c \
	algo_utils3.c \
	algo_complex.c \
	error_checker.c \
	num_checker.c \
	push_op.c \
	r_rotate_op.c \
	rotate_op.c \
	swap_op.c \
	bench_utils.c

OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
