/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:21:24 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/11 22:28:41 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

static int	sort_three(t_node **list);
static int	sort_four(t_node **stack_a, t_node **stack_b);
static int	sort_five(t_node **stack_a, t_node **stack_b);
static int	rotate_min(t_node **list, int size);

int	limit_five(t_node **list, int limit)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (limit == 2 && ((*list)->index) > ((*list)->next->index))
		sa(list);
	if (limit == 3)
		sort_three(list);
	if (limit == 4)
		sort_four(list, &stack_b);
	if (limit == 5)
		sort_five(list, &stack_b);
	return (1);
}

static int	sort_three(t_node **list)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->index;
	b = (*list)->next->index;
	c = (*list)->next->next->index;
	if ((a > b) && (b > c) && (c < a))
	{
		ra(list);
		sa(list);
	}
	else if ((a < b) && (b > c) && (c > a))
	{
		rra(list);
		sa(list);
	}
	else if ((a > b) && (b < c) && (c > a))
		sa(list);
	else if ((a > b) && (b < c) && (c < a))
		ra(list);
	else if ((a < b) && (b > c) && (c < a))
		rra(list);
	return (1);
}

static int	sort_four(t_node **stack_a, t_node **stack_b)
{
	rotate_min(stack_a, 4);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	return (0);
}

static int	sort_five(t_node **stack_a, t_node **stack_b)
{
	rotate_min(stack_a, 5);
	pb(stack_a, stack_b);
	rotate_min(stack_a, 4);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (0);
}

static int	rotate_min(t_node **list, int size)
{
	int	index;

	index = find_min(*list, size);
	move_to_top(list, index, size);
	return (1);
}
