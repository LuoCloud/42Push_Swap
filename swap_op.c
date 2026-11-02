/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:38:32 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/13 14:38:32 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	/*while (*stack != NULL)
	{
		printf("%d\n", (*stack)->value);
		*stack = (*stack)->next;
	}*/
	return ;
}

void	sa(t_node **stack_a, t_bench *bench)
{
	swap(stack_a);
	write(1, "sa\n", 3);
	bench->sa++;
	return ;
}

void	sb(t_node **stack_b, t_bench *bench)
{
	swap(stack_b);
	write(1, "sb\n", 3);
	bench->sb++;
	return ;
}

void	ss(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	bench->ss++;
	return ;
}