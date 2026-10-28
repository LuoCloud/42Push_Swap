/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:37:42 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/13 14:37:42 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	return ;
}

void	pa(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	push(stack_b, stack_a);
	emit(bench, "pa\n", 3);
	bench->pa++;
	return ;
}

void	pb(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	push(stack_a, stack_b);
	emit(bench, "pb\n", 3);
	bench->pb++;
	return ;
}

void	emit(t_bench *bench, char *op, int len)
{
	if (bench->silent)
		return ;
	write(1, op, len);
}
