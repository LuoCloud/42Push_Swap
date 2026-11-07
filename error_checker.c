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

static int	parse_flag(char *s, int *mode, t_bench *bench);

void	error_checkerfreer(char **ans, t_node *stack_a)
{
	write (2, "Error\n", 6);
	freesplit(ans);
	freestack(&stack_a);
	return ;
}


void	error_checkercont2(char **ans, int mode, int k, t_bench *bench)
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
		print_bench(bench);
		exit (0);
	}
	//checks if the inputs are already sorted.
	//here u can then pass to the algo part.
	j = disorder_calculator(stack_a);
	bench->disorder = j;
	index_creator(&stack_a, j, mode, bench);
	print_bench(bench);
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

static int	parse_flag(char *s, int *mode, t_bench *bench)
{
	if (ft_strncmp(s, "--simple", 9) == 0)
		*mode = ALGO_SIMPLE;
	else if (ft_strncmp(s, "--medium", 9) == 0)
		*mode = ALGO_MEDIUM;
	else if (ft_strncmp(s, "--complex", 10) == 0)
		*mode = ALGO_COMPLEX;
	else if (ft_strncmp(s, "--adaptive", 11) == 0)
		*mode = 0;
	else if (ft_strncmp(s, "--bench", 8) == 0)
	{
		bench->enabled = 1;
		return (1);
	}
	else
		return (0);
	bench->algo = *mode;
	if (*mode == 0)
		bench->algo = ALGO_ADAPT;
	return (1);
}

void	error_checkercont(char *strjoin, t_bench *bench)
{
	char	**ans;
	int		k;
	int		mode;

	ans = ft_split(strjoin, ' ');
	free(strjoin);
	if (!ans)
		return ;
	k = 0;
	mode = 0;
	bench->algo = ALGO_ADAPT;
	while (ans[k] && ans[k][0] == '-' && ans[k][1] == '-')
	{
		if (!parse_flag(ans[k], &mode, bench))
		{
			error_checkerfreer(ans, NULL);
			return ;
		}
		k++;
	}
	if (ans[k] == NULL)
		freesplit(ans);
	else
		error_checkercont2(ans, mode, k, bench);
}

void	helper_error_checker(char *strjoin)
{
	free(strjoin);
	write(2, "Error\n", 6);
	exit (0);
}