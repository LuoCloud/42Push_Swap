/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:45:42 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/22 18:19:34 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_algo(t_bench *bench)
{
    write(2, "[bench]", 7);
	write(2, " strategy: ", 11);
    if (bench->algo == ALGO_SIMPLE)
        ft_putstr_fd("Simple / O(n^2)", 2);
    if (bench->algo == ALGO_MEDIUM)
        ft_putstr_fd("Medium / O(n√n)", 2);
    if (bench->algo == ALGO_COMPLEX)
        ft_putstr_fd("Complex / O(n log n)", 2);
	ft_putstr_fd(bench->algo, 2);
    write(2, "\n", 1);
}

void    print_disorder(t_bench *bench)
{
    int convert;
    // 0.5 to round up
    convert = (int)(bench->disorder) * 10000 + 0.5;
    write(2, "[bench]", 7);
    write(2, " disorder: ", 11);
    ft_putnbr_fd(convert / 100, 2);
    write(2, ".", 1);
    if (convert % 100 < 10)
        write(2, "0", 1);
    ft_putnbr_fd(convert % 100, 2);
    write(2, "\n", 1);
}

void    print_pushswap(t_bench *bench)
{
    write(2, "[bench]", 7);
    write(2, " sa: ", 5);
    ft_putnbr_fd(bench->sa, 2);
    write(2, " sb: ", 5);
    ft_putnbr_fd(bench->sb, 2);
    write(2, " ss: ", 5);
    ft_putnbr_fd(bench->ss, 2);
    write(2, " pa: ", 5);
   ft_putnbr_fd(bench->pa, 2);
    write(2, " pb: ", 5);
    ft_putnbr_fd(bench->pb, 2);
    write(2, "\n", 1);
}

void    print_rotate(t_bench *bench)
{
    write(2, "[bench]", 7);
    write(2, " ra: ", 5);
    ft_putnbr_fd(bench->ra, 2);
    write(2, " rb: ", 5);
    ft_putnbr_fd(bench->rb, 2);
    write(2, " rr: ", 5);
    ft_putnbr_fd(bench->rr, 2);
    write(2, " rra: ", 5);
    ft_putnbr_fd(bench->rra, 2);
    write(2, " rrb: ", 5);
    ft_putnbr_fd(bench->rrb, 2);
    write(2, " rrr: ", 5);
    ft_putnbr_fd(bench->rrr, 2);
}

void    print_total(t_bench *bench)
{
    int total;
    
    total = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb + bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb + bench->rrr;
    if (!bench->enabled)
        return;
    write(2, "[bench]", 7);
    write(2, " total_ops: ", 12);
    ft_putnbr_fd(total, 2);
    write(2, "\n", 1);
}