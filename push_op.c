/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:37:42 by wli-ting          #+#    #+#             */
/*   Updated: 2026/11/02 21:58:35 by wli-ting         ###   ########.fr       */
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
	bench->pa++;
	write(1, "pa\n", 3);
	return ;
}

void	pb(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	push(stack_a, stack_b);
	bench->pb++;
	write(1, "pb\n", 3);
	return ;
}
