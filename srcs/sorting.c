/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:44:36 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/25 09:09:00 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_list **a, int n)
{
	t_list	*t;

	t = (*a)->n;
	if (t->p->d > t->d && t->d > t->n->d)
	{
		swap(a, n);
		rrotate(a, n);
	}
	else if (t->p->d > t->n->d && t->d < t->n->d)
		rotate(a, n);
	else if (t->p->d > t->d && t->p->d < t->n->d)
		swap(a, n);
	else if (t->p->d < t->d && t->p->d > t->n->d)
		rrotate(a, n);
	else if (t->p->d < t->n->d && t->n->d < t->d)
	{
		swap(a, n);
		rotate(a, n);
	}
}

void	reverse_sort_3(t_list **a, int n)
{
	t_list	*t;

	t = (*a)->n;
	if (ft_lstsize(*a) == 2)
	{
		if (t->p->index < t->index)
			swap(a, n);
	}
	else if (t->p->d < t->d && t->d < t->n->d)
	{
		swap(a, n);
		rrotate(a, n);
	}
	else if (t->p->d < t->n->d && t->d > t->n->d)
		rotate(a, n);
	else if (t->p->d > t->d && t->p->d < t->n->d)
		rrotate(a, n);
	else if (t->p->d < t->d && t->p->d > t->n->d)
		swap(a, n);
	else if (t->p->d > t->n->d && t->n->d > t->d)
	{
		rrotate(a, n);
		swap(a, n);
	}
}

void	sort_3intop(t_list **a, int n)
{
	t_list	*t;

	t = (*a)->n;
	if (t->p->d > t->d && t->n->d < t->d)
	{
		swap(a, n);
		rsrr(a, n);
		swap(a, n);
	}
	else if (t->d < t->n->d && t->n->d < t->p->d)
	{
		swap(a, n);
		rsrr(a, n);
	}
	else if (t->p->d < t->d && t->p->d > t->n->d)
	{
		rsrr(a, n);
		swap(a, n);
	}
	else if (t->p->d > t->d && t->p->d < t->n->d)
		swap(a, n);
	else if (t->n->d < t->d && t->n->d > t->p->d)
		rsrr(a, n);
}

void	quick_sort(t_list **a, t_list **b, int n, int c)
{
	int	i;
	int	mid;

	mid = 0;
	i = 3;
	while (ft_lstsize(*a) > 3)
	{
		mid += n / c++;
		while (i < mid && ft_lstsize(*a) > 3)
		{
			if (otrs(*a, mid) == 2 && (*a)->index > 2)
				push_and_increment(a, b, &i);
			else if ((*a)->index > (n * 10) / (25 - c) && (*a)->index < \
			(n * 10) / (24 - c) && (*a)->index < n && (*a)->index > 2)
			{
				push(a, b, 2);
				if (otrs(*a, mid))
					rotate_both(a, b, 0);
				else
					rotate(b, 2);
			}
			else
				quick_sort_part_1(a, b, mid, &i);
		}
	}
}

void	sorting(t_list **a, t_list **b, int n)
{
	if (n == 2)
	{
		if ((*a)->d > (*a)->n->d)
			swap(a, 1);
	}
	else if (n == 3)
		sort_3(a, 1);
	else if (n > 3 && n <= 11)
	{
		if (n < 7)
			push_swap_utils_4(a, b, &n);
		else
			quick_sort(a, b, n, 2);
		sort_3(a, 1);
		rev_quick_sort(a, b, n);
		while ((*a)->index != 0)
			rotate(a, 1);
	}
	else
		sorting_for_large(a, b, n);
}
