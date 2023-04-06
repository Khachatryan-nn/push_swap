/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:15:49 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/06 16:59:18 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pointer;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	pointer = *lst;
	while (pointer->next != NULL)
		pointer = pointer->next;
	pointer->next = new;
	new->prev = pointer;
}
