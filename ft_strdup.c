/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 11:34:25 by cchien-s          #+#    #+#             */
/*   Updated: 2026/08/07 11:34:25 by cchien-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	p;
	char	*ptans;

	i = 0;
	p = 0;
	while (s[i] != '\0')
		i++;
	ptans = ft_calloc(i + 1, sizeof(char));
	if (ptans == NULL)
		return (NULL);
	while (s[p] != '\0')
	{
		ptans[p] = s[p];
		p++;
	}
	ptans[p] = '\0';
	return (ptans);
}
/*int	main (void)
{
	//size_t	i;
	char	str[] = "I like potato.";
	char	*ans;

	//i = 0;
	ans = ft_strdup(str);
	if (ans == NULL)
		printf("DUplication failed.\n");
	printf("%s", ans);
	free (ans);
	ans = NULL;
	return (0);
}*/
//i + 1 bcs of the NULL terminator.