/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:37:17 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/13 14:37:17 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof (t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_back(t_node **stack, t_node *new_node)
{
	t_node	*last;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}


t_node	*helper_nodecreator(char **ans, int start_index)
{
	int		k;
	t_node	*stack_a;
	t_node	*new_node;

	stack_a = NULL;
	new_node = NULL;
	k = start_index;
	while (ans[k] != NULL)
	{
		if (num_checker(ans[k]) == 1) //checks for numbers only
		{
			error_checkerfreer (ans, stack_a);
			exit (0);
		}
		if (ft_atoi2(ans[k]) == 3000000000)
		{
			error_checkerfreer(ans, stack_a);
			exit (0);
		}
		new_node = create_node((int)ft_atoi2(ans[k]));
		add_node_back(&stack_a, new_node);
		k++;
	}
	return (stack_a);
}

unsigned int	ft_lstsize2(t_node *lst)
{
	unsigned int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}