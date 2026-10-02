/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 00:20:07 by cchien-s          #+#    #+#             */
/*   Updated: 2026/10/03 00:53:14 by cchien-s         ###   ########.fr       */
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

t_node	*create_node(int	value);
void	add_node_back(t_node **stack, t_node *new_node);
void	freestack(t_node **stack_a);
void	freesplit(char **str_array);
void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	reverserotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	push(t_node **src, t_node **dest);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	error_checker(int argc, char **argv);
void	index_creator(t_node **stack, float	j);
void	assigner(t_node **stack_a, float j);
void    simple(t_node **stack_a, t_node **stack_b);
void	complex(t_node **stack_a, t_node **stack_b);
void	move_to_top(t_node **stack_a, int pos, int size);
int 	limit_five(t_node **stack_a, int  limit);
int		num_checker(char *str);
int		num_checker2(t_node **ans);
int		is_sorted(t_node *stack_a);
int 	find_min(t_node *stack_a, int size);
unsigned int	bit_counterf (t_node **stack_a);
unsigned int	ft_lstsize2(t_node *lst);
float	disorder_calculator(t_node *stack);
unsigned int	ft_lstsize2(t_node *lst);