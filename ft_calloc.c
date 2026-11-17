/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 09:58:47 by cchien-s          #+#    #+#             */
/*   Updated: 2026/08/06 09:58:47 by cchien-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t numelements, size_t size)
{
	size_t	i;
	size_t	totalmemory;
	void	*ans;
	char	*zero;

	i = 0;
	if (numelements == 0 || size == 0)
	{
		ans = malloc(0);
		return (ans);
	}
	totalmemory = numelements * size;
	if (totalmemory / numelements != size)
		return (NULL);
	ans = malloc(totalmemory);
	if (ans == NULL)
		return (NULL);
	zero = (char *)ans;
	while (i < totalmemory)
	{
		zero[i] = 0;
		i++;
	}
	return (ans);
}
/*int	main (void)
{
	int	*ans2 = (int *)ft_calloc(5, sizeof(int));
	if (ans2 == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	for (size_t i = 0; i < 5; i++)
	{
		printf ("%d", ans2[i]);
	}
	free (ans2);
	ans2 = NULL;
	return (0);
}*/
//(totalmemory / numelements != size), this is just to 
//make sure the total memory will always stay within 
//the limits of size_t which is a 2^64. 
//we divide bcs it is a reliable checker.