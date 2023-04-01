/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:37:42 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/11 17:00:04 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p_next;

	if (!lst || !del)
		return ;
	p_next = (*lst)->next;
	while (*lst != NULL)
	{
		p_next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = p_next;
	}
	*lst = 0;
}
