/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:52:51 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/25 09:09:00 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
*There are no int like that*/
int	tnilt(t_list *a, int k)
{
	while (a)
	{
		if (a->index < k && a->index > 2)
			return (0);
		a = a->n;
	}
	return (1);
}

/*
*Additional if else's*/
void	quick_sort_part_1(t_list **a, t_list **b, int mid, int *i)
{
	if (tnilt(*a, mid) && *i < mid)
		*i = mid;
	else if (otrs(*a, mid) == 1)
		rotate(a, 1);
	else if (otrs(*a, mid) == 0)
	{
		rrotate(a, 1);
	}
	if ((*a) != NULL && (*b) != NULL)
	{
		if ((*a)->n != NULL && (*b)->n != NULL)
		{
			if ((*a)->index == (*a)->n->index + 1 && \
				(*b)->index + 1 == (*b)->n->index)
				swap_both(a, b, 0);
		}
	}
}

/*
*Pushes a to b, and increments i*/
void	push_and_increment(t_list **a, t_list **b, int *i)
{
	push(a, b, 2);
	(*i)++;
}

/*
*Does rotate, swap, rrotate*/
void	rsrr(t_list **a, int n)
{
	rotate(a, n);
	swap(a, n);
	rrotate(a, n);
}
