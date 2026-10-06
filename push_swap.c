/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 00:19:55 by cchien-s          #+#    #+#             */
/*   Updated: 2026/10/02 01:11:19 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	num_checker2(t_node **ans)
{
	t_node	*lst;
	t_node	*lst2;

	lst = *ans;
	while (lst->next != NULL)
	{
		lst2 = lst->next;
		if (lst->value == lst2->value)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	num_checker(char *str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!str || str[i] == '\0')
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')//this is to catch stadalone + or -
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

t_node	*create_node(int	value)
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

void	freestack(t_node **stack_a)
{
	t_node	*current;
	t_node	*temp;	

	if (!stack_a || !*stack_a)
		return ;
	current = *stack_a;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack_a = NULL;
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

int	is_sorted(t_node *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

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
	return (mistakes/pairs);
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

void	complex(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	unsigned int	nonodes;
	int	size;
	int	bit_increment;
	int	bit_counter;

	size = 0;
	bit_increment = 0;
	nonodes = ft_lstsize (&stack_a);
	bit_counter = bit_counterf (&stack_a);
	current = *stack_a;
	while (current->next != NULL)
	{
		while (size < nonodes)
		{
			current = *stack_a;
			if (((current->index >> bit_increment) & 1)== 1)
				ra(&stack_a);
			else
				pb (&stack_a, &stack_b);
			size++;
		}
		current = current->next;
		bit_increment++;
	}
}

void	assigner(t_node **stack_a, float j)
{
	t_node	*stack_b;
	int		size;

	stack_b = NULL;
	size = ft_lstsize2(*stack_a);
	if (size <= 5)
		limit_five(stack_a, size);
	else if (j < 0.5)
		simple(stack_a, &stack_b);
	else if (j >= 0.5)
		complex(&stack_a, &stack_b);
}

void	index_creator(t_node *stack, float	j)
{
	t_node	*temp;
	t_node	*start;

	start = stack;
	while (stack)
	{
		temp = start;
		while (temp)
		{
			if (stack->value > temp->value)
				++stack->index;
			temp = temp->next;
		}
		stack = stack->next;
	}
	assigner(&stack, j);
	return ;
}

void	error_checker(int argc, char **argv)
{
	int	i;
	int	k;
	char	**ans;
	char	*strjoin;
	char	*temp1;
	char	*temp2;
	t_node	*new_node;
	t_node	*stack_a = NULL;
	float	j;
	//t_node	*current;

	i = 1;
	k = 0;
	strjoin = ft_strdup("");
	if (argv == NULL)
		return ;
	while (i < argc)
	{
		temp1 = ft_strjoin(strjoin, argv[i]);
		temp2 = ft_strjoin(temp1, " ");
		free(strjoin);
		free(temp1);
		strjoin = temp2;
		i++;
	}//joins the inputs into one string
	ans = ft_split(strjoin, ' ');//split it into a 2D array.
	free (strjoin);
	while (ans[k] != NULL)
	{
		if (num_checker(ans[k]) == 1)//checks for numbers only
		{
			write (2, "Error\n", 6);
			freesplit(ans);
			freestack(&stack_a);
			return ;
		}
		new_node = create_node(ft_atoi(ans[k]));
		add_node_back(&stack_a, new_node);
		k++;
	}
	if (num_checker2(&stack_a) == 1)
	{
		write (2, "Error\n", 6);
		freesplit(ans);
		freestack(&stack_a);
		return ;
	}//check for repeating numbers
	if (is_sorted(stack_a) == 0)
	{
		freesplit(ans);
		freestack(&stack_a);
		exit (1);
	}//checks if the inputs are already sorted.
	//here u can then pass to the algo part.
	j = disorder_calculator(stack_a);
	index_creator(stack_a, j);
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
int	main (int argc, char *argv[])
{
	if (argc >= 2)
		error_checker(argc, argv);
	else
		write (2, "Error\n", 6);
	return (0);
}