/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:22:47 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/22 23:14:54 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static int	rot_cost(int pos, int len)
{
	if (pos <= len - pos)
		return (pos);
	return (len - pos);
}

void	rotate_b_to_top(t_node **b, int pos, int size, t_bench *bench)
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

static void	pull_pair(t_bench_info *info, int nxt, int len)
{
	int	pos;

	pos = find_rank_pos(*info->b, nxt - 1);
	rotate_b_to_top(info->b, pos, len, info->bench);
	pa(info->a, info->b, info->bench);
	len--;
	pos = find_rank_pos(*info->b, nxt);
	rotate_b_to_top(info->b, pos, len, info->bench);
	pa(info->a, info->b, info->bench);
	sa(info->a, info->bench);
}

int	pull_next(t_bench_info *info, int nxt)
{
	int	len;
	int	p1;
	int	p2;

	len = ft_lstsize2(*info->b);
	p1 = find_rank_pos(*info->b, nxt);
	p2 = -1;
	if (len > 1 && nxt >= 1)
		p2 = find_rank_pos(*info->b, nxt - 1);
	if (p2 >= 0 && rot_cost(p2, len) < rot_cost(p1, len))
	{
		pull_pair(info, nxt, len);
		return (nxt - 2);
	}
	rotate_b_to_top(info->b, p1, len, info->bench);
	pa(info->a, info->b, info->bench);
	return (nxt - 1);
}
