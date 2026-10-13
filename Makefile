# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wli-ting <wli-ting@student.42kl.edu.m      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/11 16:20:28 by wli-ting          #+#    #+#              #
#    Updated: 2026/10/11 16:46:15 by wli-ting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

SRCS = 	push_swap.c \
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

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make clean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
