/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 00:20:07 by cchien-s          #+#    #+#             */
/*   Updated: 2026/09/23 13:38:05 by wli-ting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_node
{
	int					value;
	int					index;
	struct s_node		*next;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	t_node		*bottom;
	int			size;
}	t_stack;

int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
