/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:37:39 by wli-ting          #+#    #+#             */
/*   Updated: 2026/11/07 19:09:49 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_checker2(t_node **ans)
{
	t_node	*lst;
	t_node	*lst2;

	if (!ans || !*ans)
		return (1);
	lst = *ans;
	while (lst->next != NULL)
	{
		lst2 = lst->next;
		while (lst2 != NULL)
		{
			if (lst->value == lst2->value)
				return (1);
			lst2 = lst2->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	num_checker(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}
