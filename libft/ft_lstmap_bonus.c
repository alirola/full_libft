/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alirola- <alirola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:40:17 by alirola-          #+#    #+#             */
/*   Updated: 2023/05/04 15:43:56 by alirola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*actual;

	if (!lst)
		return (NULL);
	newlist = 0;
	while (lst)
	{
		actual = ft_lstnew(f(lst->content));
		if (actual)
		{
			ft_lstadd_back(&newlist, actual);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&newlist, del);
			return (0);
		}
	}
	return (newlist);
}
