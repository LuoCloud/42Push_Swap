/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_chunk_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:22:47 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/22 23:14:54 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	flush_pend(t_bench_info *info)
{
	if (info->pend)
		rb(info->b, info->bench);
	info->pend = 0;
}

static void	spin_ra(t_bench_info *info, int count)
{
	while (count > 0)
	{
		if (info->pend)
			rr(info->a, info->b, info->bench);
		else
			ra(info->a, info->bench);
		info->pend = 0;
		count--;
	}
}

static void	spin_rra(t_bench_info *info, int count)
{
	flush_pend(info);
	while (count > 0)
	{
		rra(info->a, info->bench);
		count--;
	}
}

static void	spin_a(t_bench_info *info, int first, int last, int size)
{
	if (first < 0)
		return ;
	if (first <= size - last)
		spin_ra(info, first);
	else
		spin_rra(info, size - last);
}

void	rotate_to_chunk(t_bench_info *info, int hi)
{
	t_node	*cur;
	int		first;
	int		last;
	int		i;

	cur = *info->a;
	first = -1;
	last = -1;
	i = 0;
	while (cur)
	{
		if (cur->index < hi)
		{
			if (first < 0)
				first = i;
			last = i;
		}
		cur = cur->next;
		i++;
	}
	spin_a(info, first, last, i);
	flush_pend(info);
}
