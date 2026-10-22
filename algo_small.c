/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:21:24 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/22 23:16:44 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	sort_three(t_node **list, t_bench *bench);
static int	sort_four(t_node **stack_a, t_node **stack_b, t_bench *bench);
static int	sort_five(t_node **stack_a, t_node **stack_b, t_bench *bench);
static int	rotate_min(t_node **list, int size, t_bench *bench);

int	limit_five(t_node **list, int limit, t_bench *bench)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (limit == 2 && ((*list)->index) > ((*list)->next->index))
		sa(list, bench);
	if (limit == 3)
		sort_three(list, bench);
	if (limit == 4)
		sort_four(list, &stack_b, bench);
	if (limit == 5)
		sort_five(list, &stack_b, bench);
	return (1);
}

static int	sort_three(t_node **list, t_bench *bench)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->index;
	b = (*list)->next->index;
	c = (*list)->next->next->index;
	if ((a > b) && (b > c) && (c < a))
	{
		ra(list, bench);
		sa(list, bench);
	}
	else if ((a < b) && (b > c) && (c > a))
	{
		rra(list, bench);
		sa(list, bench);
	}
	else if ((a > b) && (b < c) && (c > a))
		sa(list, bench);
	else if ((a > b) && (b < c) && (c < a))
		ra(list, bench);
	else if ((a < b) && (b > c) && (c < a))
		rra(list, bench);
	return (1);
}

static int	sort_four(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	rotate_min(stack_a, 4, bench);
	pb(stack_a, stack_b, bench);
	sort_three(stack_a, bench);
	pa(stack_a, stack_b, bench);
	return (0);
}

static int	sort_five(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	rotate_min(stack_a, 5, bench);
	pb(stack_a, stack_b, bench);
	rotate_min(stack_a, 4, bench);
	pb(stack_a, stack_b, bench);
	sort_three(stack_a, bench);
	pa(stack_a, stack_b, bench);
	pa(stack_a, stack_b, bench);
	return (0);
}

static int	rotate_min(t_node **list, int size, t_bench *bench)
{
	int	index;

	index = find_min(*list, size);
	move_to_top(list, index, size, bench);
	return (1);
}
