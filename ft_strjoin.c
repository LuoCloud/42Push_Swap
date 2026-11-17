/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 23:46:46 by cchien-s          #+#    #+#             */
/*   Updated: 2026/08/14 01:16:53 by cchien-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ans = malloc(sizeof(char) * (ft_strlen(s1)) + (ft_strlen(s2) + 1));
	if (!ans)
		return (NULL);
	while (s1[i] != '\0')
	{
		ans[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ans[i] = s2[j];
		i++;
		j++;
	}
	ans[i] = '\0';
	return (ans);
}
/*int	main(void)
{
	char	s1[] = "Hello";
	char	s2[] = " World.";
	char	*ans;

	ans = ft_strjoin(s1, s2);
	printf("%s\n", ans);
	free (ans);
	ans = NULL;
	return (0);
}*/