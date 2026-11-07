/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 00:20:07 by cchien-s          #+#    #+#             */
/*   Updated: 2026/11/07 19:12:33 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ALGO_SIMPLE 1
# define ALGO_MEDIUM 2
# define ALGO_COMPLEX 3
# define ALGO_ADAPT 4
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	int					value;
	int					index;
	struct s_node		*next;
}	t_node;

typedef struct s_bench
{
	float	disorder;
	int		algo;
	int		enabled;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
}	t_bench;

typedef struct s_bench_info
{
	t_node	**a;
	t_node	**b;
	t_bench	*bench;
}	t_bench_info;

// Utils //
t_node			*create_node(int value);
t_node			*helper_nodecreator(char **ans, int start_index);
void			add_node_back(t_node **stack, t_node *new_node);
void			freestack(t_node **stack_a);
void			freesplit(char **str_array);
unsigned int	ft_lstsize2(t_node *lst);
long			ft_atoi2(const char *str);

// Operations //
void			rotate(t_node **stack);
void			ra(t_node **stack_a, t_bench *bench);
void			rb(t_node **stack_b, t_bench *bench);
void			rr(t_node **stack_a, t_node **stack_b, t_bench *bench);
void			reverserotate(t_node **stack);
void			rra(t_node **stack_a, t_bench *bench);
void			rrb(t_node **stack_b, t_bench *bench);
void			rrr(t_node **stack_a, t_node **stack_b, t_bench *bench);
void			swap(t_node **stack);
void			sa(t_node **stack_a, t_bench *bench);
void			sb(t_node **stack_b, t_bench *bench);
void			ss(t_node **stack_a, t_node **stack_b, t_bench *bench);
void			push(t_node **src, t_node **dest);
void			pa(t_node **stack_a, t_node **stack_b, t_bench *bench);
void			pb(t_node **stack_a, t_node **stack_b, t_bench *bench);

// Error Checker //
void			error_checker(int argc, char **argv, t_bench *bench);
void			error_checkercont(char *strjoin, t_bench *bench);
void			error_checkercont2(char **ans, int mode, int k, t_bench *bench);
void			helper_error_checker(char *strjoin);
void			error_checkerfreer(char **ans, t_node *stack_a);

// Num Checker //
int				num_checker(char *str);
int				num_checker2(t_node **ans);

// Benchmark //
void			print_algo(t_bench *bench);
void			print_disorder(t_bench *bench);
void			print_pushswap(t_bench *bench);
void			print_rotate(t_bench *bench);
void			print_total(t_bench *bench);
void			print_bench(t_bench *bench);

// Small Algorithm //
int				limit_five(t_node **stack_a, int limit, t_bench *bench);

// Simple Algorithm //
void			simple(t_node **stack_a, t_node **stack_b, t_bench *bench);
void			move_to_top(t_node **stack_a, int pos, int size,
					t_bench *bench);
int				find_min(t_node *stack_a, int size);

// Medium Algorithm //
void			medium(t_node **stack_a, t_node **stack_b, t_bench *bench);
int				bucket_count(int size);
int				find_rank_pos(t_node *stack, int rank);

// Complex Algorithm //
void			complex(t_node **stack_a, t_node **stack_b, t_bench *bench);
int				is_sorted(t_node *stack_a);
unsigned int	bit_counterf(t_node **stack_a);

// Main //
void			index_creator(t_node **stack, float j, int mode,
					t_bench *bench);
void			assigner(t_node **stack_a, float j, int mode,
					t_bench *bench);
float			disorder_calculator(t_node *stack);

#endif
