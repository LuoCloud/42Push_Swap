/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 19:08:39 by cchien-s          #+#    #+#             */
/*   Updated: 2026/08/13 19:08:39 by cchien-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	char	*strlst = "I like potato.";
	char	*strnew = "Its correct.";

	t_list	*test1 = ft_lstnew(strlst);
	t_list	*test2 = ft_lstnew(strnew);

	ft_lstadd_front(test1, test2);
}*/