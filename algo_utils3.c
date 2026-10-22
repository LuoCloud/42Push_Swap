/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:37:32 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/13 14:37:32 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freestack(t_node **stacka)
{
	t_node	*current;
	t_node	*temp;	

	if (!stacka || !*stacka)
		return ;
	current = *stacka;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stacka = NULL;
}

void	freesplit(char **str_array)
{
	int	i;

	i = 0;
	if (!str_array)
		return ;
	while (str_array[i] != NULL)
	{
		free(str_array[i]);
		i++;
	}
	free (str_array);
}

long	ft_atoi2(const char *str)
{
	unsigned int	i;
	long			j;
	int				l;

	i = 0;
	j = 0;
	l = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			l = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		j = (j * 10) + (str[i] - 48);
		if ((j * l) > 2147483647 || (j * l) < -2147483648)
			return (3000000000);
		i++;
	}
	return ((int)(l * j));
}

void	print_bench(t_bench *bench)
{
	if (!bench->enabled)
		return ;
	print_disorder(bench);
	print_algo(bench);
	print_total(bench);
	print_pushswap(bench);
	print_rotate(bench);
}