/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:37:42 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/06 16:59:19 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*p_next;

	if (!lst)
		return ;
	p_next = (*lst)->next;
	while (*lst != NULL)
	{
		p_next = (*lst)->next;
		free(*lst);
		*lst = p_next;
	}
	*lst = 0;
}
