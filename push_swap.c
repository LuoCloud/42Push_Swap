/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 00:19:55 by cchien-s          #+#    #+#             */
/*   Updated: 2026/09/24 03:12:45 by cchien-s         ###   ########.fr       */
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

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
	return ;
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	return ;
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	return ;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	return ;
}

void	reverserotate(t_node **stack)
{
	t_node	*second_last;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	second_last = *stack;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *stack;
	*stack = last;
	second_last->next = NULL;
	return ;
}

void	rra(t_node **stack_a)
{
	reverserotate(stack_a);
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_node **stack_b)
{
	reverserotate(stack_b);
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverserotate(stack_a);
	reverserotate(stack_b);
	write(1, "rrr\n", 4);
	return ;
}

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if(!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first = second->next;
	second->next = first;
	second = *stack;
	/*while (*stack != NULL)
	{
		printf("%d\n", (*stack)->value);
		*stack = (*stack)->next;
	}*/
	return ;
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
	return ;
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	return ;
}

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (!src || !*src || !(*src)->next)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	return ;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
	return ;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
	return ;
}

void	index_creator(t_node *stack)
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
	sa(&stack);
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
	index_creator(stack_a);
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