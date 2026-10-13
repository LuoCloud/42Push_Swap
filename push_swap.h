/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 00:20:07 by cchien-s          #+#    #+#             */
/*   Updated: 2026/10/13 14:37:51 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_node
{
	int					value;
	int					index;
	struct s_node		*next;
}	t_node;

typedef struct s_bench
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
}	t_bench;


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
void			ra(t_node **stack_a);
void			rb(t_node **stack_b);
void			rr(t_node **stack_a, t_node **stack_b);
void			reverserotate(t_node **stack);
void			rra(t_node **stack_a);
void			rrb(t_node **stack_b);
void			rrr(t_node **stack_a, t_node **stack_b);
void			swap(t_node **stack);
void			sa(t_node **stack_a);
void			sb(t_node **stack_b);
void			ss(t_node **stack_a, t_node **stack_b);
void			push(t_node **src, t_node **dest);
void			pa(t_node **stack_a, t_node **stack_b);
void		 	pb(t_node **stack_a, t_node **stack_b);

// Error Checker //
void			error_checker(int argc, char **argv);
void			error_checkercont(char *strjoin);
void			error_checkercont2(char **ans, int mode, int k);
void			helper_error_checker(char *strjoin);

// Num Checker //
int				num_checker(char *str);
int				num_checker2(t_node **ans);

// Small Algorithm //
int				limit_five(t_node **stack_a, int  limit);

// Simple Algorithm //
void			simple(t_node **stack_a, t_node **stack_b);
void			move_to_top(t_node **stack_a, int pos, int size);
int				find_min(t_node *stack_a, int size);

// Medium Algorithm //
void 			medium(t_node **stack_a, t_node **stack_b);
int				bucket_count(int size);
int				find_rank_pos(t_node *stack, int rank);

// Complex Algorithm //
void			complex(t_node **stack_a, t_node **stack_b);
int				is_sorted(t_node *stack_a);
unsigned int	bit_counterf(t_node **stack_a);

// Main //
void			index_creator(t_node **stack, float j, int mode);
void		 	assigner(t_node **stack_a, float j, int mode);
float			disorder_calculator(t_node *stack);