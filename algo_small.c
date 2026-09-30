#include "push_swap.h"
#include <stdio.h>

int limit_five(t_node **list, int  limit)
{
    t_node *stack_b;

    stack_b = NULL;
    if (limit == 2)
    {
        if (((*list)->index) > ((*list)->next->index))
            sa(list);
        return (1);
    }
    if (limit == 3)
    {
        sort_three(list);
        return (1);
    }
    if (limit == 4)
        sort_four(list, &stack_b);
    if (limit == 5)
        sort_five(list, &stack_b);
    return (0);
}

int sort_three(t_node **list)
{
    int a;
    int b;
    int c;

    a = (*list)->index;
    b = (*list)->next->index;
    c = (*list)->next->next->index;
    if ((a > b) && (b > c) && (c < a))
    {
        ra(list);
        sa(list);
    }
    else if ((a < b) && (b > c) && (c > a))
    {
        rra(list);
        sa(list);
    }
    else if ((a > b) && (b < c) && (c < a))
        ra(list);
    else if ((a < b) && (b > c) && (c < a))
        rra(list);
    return (1);
}

int sort_four(t_node **stack_a, t_node **stack_b)
{
    rotate_min(stack_a, 4);
    pb(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_a, stack_b);
    return (1);
}

int sort_five(t_node **stack_a, t_node **stack_b)
{
    rotate_min(stack_a, 5);
    pb(stack_a, stack_b);
    rotate_min(stack_a, 4);
    pb(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    return (1);
}

int find_min(t_node *list, int size)
{
    t_node  *temp;
    int min;
    int index;
    int i;

    temp = list;
    min = temp->index;
    i = 0;
    index = 0;
    while (i < size)
    {
        if (temp->index < min)
        {
            min = temp->index;
            index = i;
        }
        temp = temp->next;
        i++;
    }
    return (index);
}

int rotate_min(t_node **list, int size)
{
    int index;
    int i;

    index = find_min(*list, size);
    i = 0;
    while (i < index)
    {
        ra(list);
        i++;
    }
    return (1);
}