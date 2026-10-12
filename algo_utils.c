/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 02:58:27 by cchien-s          #+#    #+#             */
/*   Updated: 2026/10/13 02:58:27 by cchien-s         ###   ########.fr       */
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

int	find_rank_pos(t_node *stack, int rank)
{
	int	i;

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
