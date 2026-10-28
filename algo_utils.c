/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:37:12 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/13 14:37:12 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h>

int	chunk_base(int size)
{
	int	root;

	root = 1;
	while ((root + 1) * (root + 1) <= size)
		root++;
	root = (7 * root + 5) / 10;
	if (root < 1)
		root = 1;
	return (root);
}

int	chunk_cost(t_node *a, int n, int k)
{
	t_node			*copy;
	t_node			*b;
	t_bench			tmp;
	t_bench_info	info;

	copy = clone_stack(a);
	if (!copy)
		return (-1);
	b = NULL;
	ft_bzero(&tmp, sizeof(t_bench));
	tmp.silent = 1;
	info.a = &copy;
	info.b = &b;
	info.bench = &tmp;
	chunk_push(&info, n, k);
	chunk_pull(&info, n);
	freestack(&copy);
	return (bench_total(&tmp));
}

int	best_chunk(t_node *a, int n)
{
	int	k;
	int	hi;
	int	best;
	int	cost;
	int	best_cost;

	k = chunk_base(n) - 3;
	hi = chunk_base(n) + 3;
	if (k < 1)
		k = 1;
	best = k;
	best_cost = -1;
	while (k <= hi && k <= n)
	{
		cost = chunk_cost(a, n, k);
		if (cost >= 0 && (best_cost < 0 || cost < best_cost))
		{
			best = k;
			best_cost = cost;
		}
		k++;
	}
	return (best);
}

int find_rank_pos(t_node *stack, int rank)
{
    int i;

    i = 0;
    while (stack)
    {
        if (((stack)->index) == rank)
            return (i);
        stack = (stack)->next;
        i++;
    }
    return (-1);
}

void	index_creator(t_node **stack, float j, int mode, t_bench *bench)
{
	t_node	*temp;
	t_node	*current;
	t_node	*start;

	if (!stack || !(*stack)->next || j == 0.0)
		return ;
	start = *stack;
	current = *stack;
	while (current)
	{
		temp = start;
		while (temp)
		{
			if (current->value > temp->value)
				++current->index;
			temp = temp->next;
		}
		current = current->next;
	}
	assigner(stack, j, mode, bench);
	return ;
}
