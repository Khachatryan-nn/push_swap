/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:19:30 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/10 22:05:27 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*pointer;

	if (!lst)
		return (NULL);
	pointer = lst;
	while (pointer->next != NULL)
		pointer = pointer->next;
	return (pointer);
}
