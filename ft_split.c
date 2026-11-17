/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 22:33:19 by cchien-s          #+#    #+#             */
/*   Updated: 2026/08/17 01:55:30 by cchien-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*printerofwords(char const *s, char c)
{
	size_t	pos;
	char	*word;
	size_t	count;

	pos = 0;
	count = 0;
	while (s[pos] != c && s[pos] != '\0')
		pos++;
	word = malloc((sizeof(char) * pos) + 1);
	if (!word)
		return (NULL);
	while (count < pos)
	{
		word[count] = s[count];
		count++;
	}
	word[count] = '\0';
	return (word);
}

static int	counterofwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static void	*free_array(char **ans, size_t j)
{
	while (j > 0)
	{
		j--;
		free(ans[j]);
	}
	free(ans);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	size_t	j;

	if (!s)
		return (NULL);
	ans = malloc(sizeof(char *) * (counterofwords(s, c) + 1));
	if (!ans)
		return (NULL);
	j = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			ans[j] = printerofwords(s, c);
			if (!ans[j])
				return (free_array(ans, j));
			j++;
			while (*s && *s != c)
				s++;
		}
	}
	ans[j] = NULL;
	return (ans);
}
/*int main(void)
{
	char    **ans = NULL;
	size_t  i;

	i = 0;
	ans = ft_split(" hello   world 42 .", ' ');
	while (ans[i] != NULL)
	{
		printf("Position %zu: is the word %s.\n", i, ans[i]);
		i++;
	}
	free (ans);
	ans = NULL;
	return (0);
}*/