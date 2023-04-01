/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:45:01 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/11 16:57:51 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*pointer;

	if (!lst || !f)
		return ;
	pointer = lst;
	while (pointer != NULL)
	{
		f(pointer->content);
		pointer = pointer->next;
	}
}
