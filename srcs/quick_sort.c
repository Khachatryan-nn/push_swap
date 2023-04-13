/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:06:14 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/13 00:06:37 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	midpoint(int mid, int len)
{
	return ((mid + len) / 2/* + (mid + len) % 2*/);
}

int	on_the_right_side(t_list *start, int mid)
{
	int	len;

	len = ft_lstsize(start);
	while (len--)
	{
		if (start->d < mid)
			return (1);
		else
			start = start->n;
	}
	return (0);
}