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

int	bucket_count(int size)
{
	int	root;

	root = 1;
	while ((root * root) <= size)
		root++;
	root--;
	root = root / 2;
	if (root < 1)
		root = 1;
	return (root);
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

void	index_creator(t_node **stack, float j, int mode)
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
	assigner(stack, j, mode);
	return ;
}
