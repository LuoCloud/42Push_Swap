/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wli-ting <wli-ting@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:45:42 by wli-ting          #+#    #+#             */
/*   Updated: 2026/10/22 22:18:03 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_algo(t_bench *bench)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (bench->algo == ALGO_SIMPLE)
		ft_putstr_fd("Simple / O(n^2)", 2);
	else if (bench->algo == ALGO_MEDIUM)
		ft_putstr_fd("Medium / O(n√n)", 2);
	else if (bench->algo == ALGO_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)", 2);
	else if (bench->picked == ALGO_MEDIUM)
		ft_putstr_fd("Adaptive / O(n√n)", 2);
	else if (bench->picked == ALGO_COMPLEX)
		ft_putstr_fd("Adaptive / O(n log n)", 2);
	else
		ft_putstr_fd("Adaptive / O(n^2)", 2);
	ft_putstr_fd("\n", 2);
}

void	print_disorder(t_bench *bench)
{
	int	convert;

	convert = (int)(bench->disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(convert / 100, 2);
	ft_putstr_fd(".", 2);
	if (convert % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(convert % 100, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_pushswap(t_bench *bench)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n", 2);
}

void	print_rotate(t_bench *bench)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_total(t_bench *bench)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench_total(bench), 2);
	ft_putstr_fd("\n", 2);
}
