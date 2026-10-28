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

void	chunk_push(t_bench_info *info, int n, int k)
{
	int	size;
	int	pushed;
	int	hi;
	int	v;

	size = (n + k - 1) / k;
	pushed = 0;
	info->pend = 0;
	while (*info->a)
	{
		hi = pushed + size;
		if (hi > n)
			hi = n;
		rotate_to_chunk(info, hi);
		v = (*info->a)->index;
		pb(info->a, info->b, info->bench);
		pushed++;
		if (v < hi - size)
			info->pend = 1;
	}
	flush_pend(info);
}

void	chunk_pull(t_bench_info *info, int n)
{
	int	nxt;

	nxt = n - 1;
	while (*info->b)
		nxt = pull_next(info, nxt);
}

void	medium(t_node **a, t_node **b, t_bench *bench)
{
	t_bench_info	info;
	int				n;
	int				k;

	n = ft_lstsize2(*a);
	k = best_chunk(*a, n);
	info.a = a;
	info.b = b;
	info.bench = bench;
	chunk_push(&info, n, k);
	chunk_pull(&info, n);
}
