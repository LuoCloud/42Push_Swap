/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:38:28 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/13 14:38:28 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
	return ;
}

void	ra(t_node **stack_a)
{
	t_bench	*bench;

	rotate(stack_a);
	write(1, "ra\n", 3);
	bench->ra++;
	return ;
}

void	rb(t_node **stack_b)
{
	t_bench	*bench;

	rotate(stack_b);
	write(1, "rb\n", 3);
	bench->rb++;
	return ;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	t_bench	*bench;

	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	bench->rr++;
	return ;
}
