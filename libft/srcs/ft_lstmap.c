/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:00:53 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/11 18:34:35 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*pointer;
	t_list	*new;
	t_list	*nodes;

	if (!lst || !f)
		return (NULL);
	nodes = ft_lstnew(f(lst->content));
	if (!nodes)
		return (NULL);
	pointer = nodes;
	new = 0;
	lst = lst->next;
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			ft_lstclear(&nodes, del);
		pointer->next = new;
		pointer = new;
		lst = lst->next;
	}
	return (nodes);
}
