/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:29:22 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/13 14:29:22 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	bit_counterf(t_node **stack_a)
{
	t_node			*current;
	unsigned int	count;
	int				max_index;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	current = *stack_a;
	count = 0;
	max_index = 0;
	while (current != NULL)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	while ((max_index >> count) != 0)
		count++;
	return (count);
}

int	is_sorted(t_node *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	complex(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	t_node			*current;
	unsigned int	nonodes;
	unsigned int	size;
	unsigned int	bit_increment;

	bit_increment = 0;
	nonodes = ft_lstsize2(*stack_a);
	while (bit_increment < bit_counterf(stack_a))
	{
		size = 0;
		if (is_sorted (*stack_a) == 0)
			break ;
		while (size < nonodes)
		{
			current = *stack_a;
			if (((current->index >> bit_increment) & 1) == 1)
				ra(stack_a, bench);
			else
				pb (stack_a, stack_b, bench);
			size++;
		}
		while (*stack_b != NULL)
			pa (stack_a, stack_b, bench);
		bit_increment++;
	}
}
