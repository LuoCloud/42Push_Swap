NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c \
	ft_split.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strdup.c\
	ft_calloc.c\
	push_swap.c \
	algo_small.c\
	algo_simple.c \
	algo_medium.c \
	algo_utils.c \
	operations.c \

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft	
LIBFT = ./libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

# This rule takes your compiled objects and the libft.a, and links them into an executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make clean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re