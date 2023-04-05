/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:45:01 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/04 18:24:50 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int ))
{
	t_list	*pointer;

	if (!lst || !f)
		return ;
	pointer = lst;
	while (pointer != NULL)
	{
		f(pointer->data);
		pointer = pointer->next;
	}
}
