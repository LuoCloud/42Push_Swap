/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:22:47 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/22 23:14:54 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_bucket(t_node **a, t_node **b, int lower, int upper, t_bench *bench);
static void	distribute_bucket(t_node **a, t_node **b, int lower, int upper, t_bench *bench);
static void	rotate_b_to_top(t_node **b, int pos, int size, t_bench *bench);
static void	move_rank_a(t_node **a, t_node **b, int rank, t_bench *bench);

static void	distribute_bucket(t_bench_info *info, int lower, int upper)
{
	int	size;

	size = ft_lstsize2(*info->a);
	while (size > 0)
	{
		if ((*info->a)->index >= lower && (*info->a)->index < upper)
			pb(info->a, info->b, info->bench);
		else
			ra(info->a, info->bench);
		size--;
	}
}

static void	rotate_b_to_top(t_node **b, int pos, int size, t_bench *bench)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(b, bench);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rrb(b, bench);
			pos--;
		}
	}
}

static void	move_rank_a(t_node **a, t_node **b, int rank, t_bench *bench)
{
	int	pos;

	pos = find_rank_pos(*b, rank);
	if (pos < 0)
		return ;
	rotate_b_to_top(b, pos, ft_lstsize2(*b), bench);
	pa(a, b, bench);
}

static void	sort_bucket(t_bench_info *info, int lower, int upper)
{
	int	rank;

	rank = upper - 1;
	while (rank >= lower)
	{
		move_rank_a(info->a, info->b, rank, info->bench);
		rank--;
	}
}

void	medium(t_node **a, t_node **b, t_bench *bench)
{
	t_bench_info	info;
	int	size;
	int	bucket;
	int	upper;
	int	lower;

	info.a = a;
	info.b = b;
	info.bench = bench;
	size = ft_lstsize2(*a);
	bucket = (size + bucket_count(size) - 1) / bucket_count(size);
	upper = size;
	while (upper > 0)
	{
		lower = upper - bucket;
		if (lower < 0)
			lower = 0;
		distribute_bucket(&info, lower, upper, bench);
		sort_bucket(&info, lower, upper, bench);
		upper = lower;
	}
}
