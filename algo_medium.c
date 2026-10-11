/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:22:47 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/11 16:51:09 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_bucket(t_node **a, t_node **b, int lower, int upper);
static void	distribute_bucket(t_node **a, t_node **b, int lower, int upper);
static void	rotate_b_to_top(t_node **b, int pos, int size);
static void	move_rank_a(t_node **a, t_node **b, int rank);

static void	distribute_bucket(t_node **a, t_node **b, int lower, int upper)
{
	int	size;

	size = ft_lstsize2(*a);
	while (size > 0)
	{
		if ((*a)->index >= lower && (*a)->index < upper)
			pb(a, b);
		else
			ra(a);
		size--;
	}
}

static void	rotate_b_to_top(t_node **b, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(b);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rrb(b);
			pos--;
		}
	}
}

static void	move_rank_a(t_node **a, t_node **b, int rank)
{
	int	pos;

	pos = find_rank_pos(*b, rank);
	if (pos < 0)
		return ;
	rotate_b_to_top(b, pos, ft_lstsize2(*b));
	pa(a, b);
}

static void	sort_bucket(t_node **a, t_node **b, int lower, int upper)
{
	int	rank;

	rank = upper - 1;
	while (rank >= lower)
	{
		move_rank_a(a, b, rank);
		rank--;
	}
}

void	medium(t_node **a, t_node **b)
{
	int	size;
	int	bucket;
	int	upper;
	int	lower;

	size = ft_lstsize2(*a);
	bucket = (size + bucket_count(size) - 1) / bucket_count(size);
	upper = size;
	while (upper > 0)
	{
		lower = upper - bucket;
		if (lower < 0)
			lower = 0;
		distribute_bucket(a, b, lower, upper);
		sort_bucket(a, b, lower, upper);
		upper = lower;
	}
}
