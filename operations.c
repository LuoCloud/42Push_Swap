#include "push_swap.h"

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

unsigned int	bit_counterf (t_node **stack_a)
{
	t_node	*current;
	unsigned int count;
	int	max_index;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	current = *stack_a;
	count = 0;
	max_index = 0;
	while (current != NULL)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	while ((max_index >> count) != 0)
		count++;
	return (count);
}
