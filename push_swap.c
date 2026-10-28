/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 00:19:55 by cchien-s          #+#    #+#             */
/*   Updated: 2026/10/13 14:37:51 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder_calculator(t_node *stack)
{
	t_node	*current;
	t_node	*addiofcurrent;
	float	mistakes;
	float	pairs;

	pairs = 0.0;
	mistakes = 0.0;
	if (!stack || stack->next == NULL)
		return (0.0);
	current = stack;
	while (current->next != NULL)
	{
		addiofcurrent = current->next;
		while (addiofcurrent != NULL)
		{
			pairs++;
			if (current->value > addiofcurrent->value)
				mistakes++;
			addiofcurrent = addiofcurrent->next;
		}
		current = current->next;
	}
	return (mistakes / pairs);
}



/*void	testprint (t_node **stack_a)
{
	t_node	*current;

	current = *stack_a;
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}*/



static int	pick_algo(int size, float j)
{
	if (size > 1500 && j >= 0.2)
		return (ALGO_COMPLEX);
	return (ALGO_MEDIUM);
}

void	assigner(t_node **stack_a, float j, int mode, t_bench *bench)
{
	t_node	*stack_b;
	int		size;

	stack_b = NULL;
	size = ft_lstsize2(*stack_a);
	if (mode == 0 && size <= 5)
	{
		bench->picked = ALGO_SIMPLE;
		limit_five(stack_a, size, bench);
		return ;
	}
	if (mode == 0)
		mode = pick_algo(size, j);
	bench->picked = mode;
	if (mode == ALGO_SIMPLE)
		simple(stack_a, &stack_b, bench);
	else if (mode == ALGO_MEDIUM)
		medium(stack_a, &stack_b, bench);
	else
		complex(stack_a, &stack_b, bench);
}

void	error_checker(int argc, char **argv, t_bench *bench)
{
	int		i;
	char	*temp1;
	char	*temp2;
	char	*strjoin;

	i = 1;
	if (argv == NULL)
		return ;
	strjoin = ft_strdup("");
	while (i < argc)
	{
		temp1 = ft_strjoin(strjoin, argv[i]);
		temp2 = ft_strjoin(temp1, " ");
		free(strjoin);
		free(temp1);
		strjoin = temp2;
		i++;
	}
	error_checkercont(strjoin, bench);
	//joins the inputs into one string
	//free(temp2);
	/*else
		helper_error_checker(strjoin);*/
}

int	main(int argc, char *argv[])
{
	t_bench	bench;

	ft_bzero(&bench, sizeof(t_bench));
	if (argc >= 2 && has_blank_arg(argc, argv))
		write(2, "Error\n", 6);
	else if (argc >= 2)
		error_checker(argc, argv, &bench);
	return (0);
}