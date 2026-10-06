#include "push_swap.h"
#include <stdio.h>

static void    sort_value(t_node **stack_a, t_node **stack_b, int lower, int upper);
static void    sort_value(t_node **stack_a, t_node **stack_b, int lower, int upper);

void    medium(t_node **stack_a, t_node **stack_b)
{
    int size;
    int bucket;
    int upper;
    int lower;

    size = ft_lstsize2(stack_a);
    bucket = (size / bucket_count(size));
    upper = size;
    while (upper > 0)
    {
        lower = upper - bucket;
        if (lower < 0)
            lower = 0;
        sort_bucket(stack_a, stack_b, lower, upper);       
        sort_value(stack_a, stack_b, lower, upper);
        upper = lower;       
    }
}

void    sort_bucket(t_node **stack_a, t_node **stack_b, int lower, int upper)
{
    int size;

    size = ft_lstsize2(stack_a);
    while (size > 0)
    {
        if ((stack_a)->index >= lower && (stack_a)->index < upper)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        size--;
    }
}

static void    sort_value(t_node **stack_a, t_node **stack_b, int lower, int upper)
{
    int rank;

    rank = upper - 1;
    while (rank >= lower)
    {
        move_rank_a(stack_a, stack_b, rank);
        rank--;
    }
}

static void    move_rank_a(t_node **stack_a, t_node **stack_b, int rank)
{
    int size;
    int pos;

    size = ft_lstsize2(stack_b);
    pos = find_rank_pos(*stack_b, rank);
    if (pos <= size / 2)
    {
        while (pos > 0)
        {
            rb(stack_b);
            pos--;
        }
    }
    else
    {
        pos = size - pos;
        while (pos > 0)
        {
            rrb(stack_b);
            pos--;
        }
    }
    pa(stack_a, stack_b);
}