/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:16:05 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/26 17:46:54 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_quick_sort_part_1(t_list **a, t_list **b, int *i, int *j)
{
	push(b, a, 1);
	(*j)--;
	if (*i > 0)
	{
		if ((*a)->index > (*a)->n->index)
			swap(a, 1);
		*j -= *i;
		while (--(*i) && (*b) != NULL)
		{
			if (!mor(*b, *j))
				rrotate_both(a, b, 0);
			else
				rrotate(a, 1);
		}
		if ((*a)->index > (*a)->n->index)
			swap(a, 1);
	}
}

void	rev_quick_sort_part_2(t_list **a, t_list **b, int *i, int j)
{
	push(b, a, 1);
	(*i)++;
	if (*i > 1)
	{
		if (mor(*b, j) == 1)
			rotate_both(a, b, 0);
		else
			rotate(a, 1);
	}
}

void	rev_quick_sort_part_3(t_list **a, t_list **b, int j, int *c)
{
	(*c)++;
	push(b, a, 1);
	if (mor(*b, j))
		rotate_both(a, b, 0);
	else
		rotate(a, 1);
}

void	rev_quick_sort_part_4(t_list **a, t_list **b, int j)
{
	if (mor(*b, j) == 1)
		rotate(b, 2);
	else if (mor(*b, j) == 0)
		rrotate(b, 2);
	if ((*a)->index == (*a)->n->index + 1 && \
		(*b)->index == (*b)->n->index - 1)
		swap_both(a, b, 0);
}

void	push_swap_utils_4(t_list **a, t_list **b, int *n)
{
	while (*n > 3)
	{
		if ((*a)->index > 2)
		{
			push(a, b, 2);
			(*n)--;
		}
		else if (otrs(*a, *n + 1) == 0)
			rrotate(a, 1);
		else if (otrs(*a, *n + 1) == 1)
			rotate(a, 1);
	}
	if (ft_lstsize(*b) > 1)
		reverse_sort_3(b, 2);
	sort_3(a, 1);
	while (*b)
		push(b, a, 1);
	while ((*a)->index != 0)
		rotate(a, 1);
}
