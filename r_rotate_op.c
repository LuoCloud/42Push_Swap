/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:38:25 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/13 14:38:25 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverserotate(t_node **stack)
{
	t_node	*second_last;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	second_last = *stack;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *stack;
	*stack = last;
	second_last->next = NULL;
	return ;
}

void	rra(t_node **stack_a)
{
	reverserotate(stack_a);
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_node **stack_b)
{
	reverserotate(stack_b);
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverserotate(stack_a);
	reverserotate(stack_b);
	write(1, "rrr\n", 4);
	return ;
}