/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchien-s <cchien-s@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 00:25:34 by cchien-s          #+#    #+#             */
/*   Updated: 2026/08/19 23:54:09 by cchien-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node -> next = new;
}
/*int	main(void)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*unknown;
	t_list	**huge;

	huge = malloc(sizeof(t_list) * ft_lstsize(huge) + 1);
	first = ft_lstnew("I");
	second = ft_lstnew("like");
	third = ft_lstnew("Potato");
	unknown = ft_lstnew("Gayy");

	first->content = "I";
	second->content = "like";
	third->content = "potato";
	unknown->content = "Gayyy";

	first->next = second;
	second->next = third;
	third->next = NULL;

	while (first != NULL)
	{
		*huge = first;
		huge++;
		first = first->next;
	}
	ft_lstadd_back(huge, unknown);
	free (huge);
	free (first);
	free (second);
	free (third);
	return (0);
}*/