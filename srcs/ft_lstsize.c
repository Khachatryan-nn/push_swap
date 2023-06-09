/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:01:58 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/11 17:31:50 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*pointer;

	if (!lst)
		return (0);
	i = 0;
	pointer = lst;
	while (pointer != NULL)
	{
		pointer = pointer->n;
		i++;
	}
	return (i);
}
