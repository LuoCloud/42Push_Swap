/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:37:35 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/13 14:37:35 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_checkerfreer(char **ans, t_node *stack_a)
{
	write (2, "Error\n", 6);
	freesplit(ans);
	freestack(&stack_a);
	return ;
}


void	error_checkercont2(char **ans, int mode, int k)
{
	float	j;
	t_node	*stack_a;

	j = 0.0;
	stack_a = helper_nodecreator (ans, k);
	if (num_checker2(&stack_a) == 1)
	{
		error_checkerfreer (ans, stack_a);
		return ;
	}
	//check for repeating numbers
	if (is_sorted(stack_a) == 0)
	{
		freesplit(ans);
		freestack(&stack_a);
		exit (0);
	}
	//checks if the inputs are already sorted.
	//here u can then pass to the algo part.
	j = disorder_calculator(stack_a);
	index_creator(&stack_a, j, mode);
	//printf("%f\n", j);
	/*current = stack_a;
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}*/
	freesplit(ans);
	freestack(&stack_a);
	return ;
}

void	error_checkercont(char *strjoin)
{
	char	**ans;

	ans = ft_split(strjoin, ' ');//split it into a 2D array.
	free (strjoin);
	if (ans[0] != NULL && ans[0][0] == '-' && ans[0][1] == '-')
	{
		if (ft_strncmp(ans[0], "--simple", 9) == 0)
			error_checkercont2 (ans, 1, 1);
		else if (ft_strncmp(ans[0], "--medium", 9) == 0)
			error_checkercont2 (ans, 2, 1);
		else if (ft_strncmp(ans[0], "--complex", 10) == 0)
			error_checkercont2 (ans, 3, 1);
		else if (ft_strncmp(ans[0], "--adaptive", 11) == 0)
			error_checkercont2 (ans, 0, 1);
		else if (ft_strncmp(ans[0], "--bench", 8) == 0)
			error_checkercont2 (ans, 0, 1);
		else
		{
			write(2, "Error\n", 6);
			freesplit(ans);
			return ;
		}
		return ;
	}
	error_checkercont2 (ans, 0, 0);
}

void	helper_error_checker(char *strjoin)
{
	free(strjoin);
	write(2, "Error\n", 6);
	exit (0);
}