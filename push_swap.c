/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:37:51 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/13 14:37:51 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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



void	assigner(t_node **stack_a, float j, int mode)
{
	t_node	*stack_b;
	int		size;

	stack_b = NULL;
	size = ft_lstsize2(*stack_a);
	if (mode >= 1 && mode <= 3)
	{
		if (mode == 1)
			simple(stack_a, &stack_b);
		else if (mode == 2)
			medium(stack_a, &stack_b);
		else if (mode == 3)
			complex(stack_a, &stack_b);
	}
	if (size <= 5 && mode == 0)
		limit_five(stack_a, size);
	else if (j < 0.2 && mode == 0)
		simple(stack_a, &stack_b);
	else if (j >= 0.2 && j < 0.5 && mode == 0)
		medium(stack_a, &stack_b);
	else if (j >= 0.5 && mode == 0)
		complex(stack_a, &stack_b);
}

void	error_checker(int argc, char **argv)
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
	error_checkercont (strjoin);
	//joins the inputs into one string
	//free(temp2);
	/*else
		helper_error_checker(strjoin);*/
}

int	main(int argc, char *argv[])
{
	if (argc >= 2)
		error_checker(argc, argv);
	return (0);
}