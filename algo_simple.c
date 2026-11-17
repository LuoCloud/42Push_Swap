/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:22:24 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/22 23:26:50 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_node *list, int size)
{
	int	min;
	int	index;
	int	i;

	min = list->index;
	i = 0;
	index = 0;
	while (i < size)
	{
		if (list->index < min)
		{
			min = list->index;
			index = i;
		}
		list = list->next;
		i++;
	}
	return (index);
}

void	move_to_top(t_node **stack_a, int pos, int size, t_bench *bench)
{
	int	i;

	i = 0;
	if (pos <= size / 2)
	{
		while (i < pos)
		{
			ra(stack_a, bench);
			i++;
		}
	}
	else
	{
		while (i < size - pos)
		{
			rra(stack_a, bench);
			i++;
		}
	}
}

void	simple(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	pos;
	int	size;

	size = ft_lstsize2(*stack_a);
	while (size > 0)
	{
		pos = find_min(*stack_a, size);
		move_to_top(stack_a, pos, size, bench);
		pb(stack_a, stack_b, bench);
		size--;
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b, bench);
}
