/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:00:53 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/03 17:09:19 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(int ), void (*del)(void *))
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
		new = ft_lstnew(f(lst->data));
		if (!new)
			ft_lstclear(&nodes, del);
		pointer->next = new;
		pointer = new;
		lst = lst->next;
	}
	return (nodes);
}
