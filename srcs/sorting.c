/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:44:36 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/13 18:49:40 by tikhacha         ###   ########.fr       */
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
	if (t->p->d < t->d && t->d < t->n->d)
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

// void	parallel_sort(t_list **a, t_list **b)
// {
// 	t_list	*ta;
// 	t_list	*tb;

// 	ta = (*a)->n;
// 	tb = (*b)->n;
// 	if (need_sw(a) && need_sw(b))
// 	{
// 		swap(a, 3);
// 		swap(b, 3);
// 		write (1, "ss\n", 1);
// 	}
// }

void	sort_3intop(t_list **a, int n)
{
	t_list	*t;

	t = (*a)->n;
	if (t->p->d > t->d && t->n->d < t->d)
	{
		swap(a, n);
		rotate(a, n);
		swap(a, n);
		rrotate(a, n);
		swap(a, n);
	}
	else if (t->d < t->n->d && t->n->d < t->p->d)
	{
		swap(a, n);
		rotate(a, n);
		swap(a, n);
		rrotate(a, n);
	}
	else if (t->p->d < t->d && t->p->d > t->n->d)
	{
		rotate(a, n);
		swap(a, n);
		rrotate(a, n);
		swap(a, n);
	}
	else if (t->p->d > t->d && t->p->d < t->n->d)
		swap(a, n);
	else if (t->n->d < t->d && t->n->d > t->p->d)
	{
		rotate(a, n);
		swap(a, n);
		rrotate(a, n);
	}
}

void	quick_sort(t_list **a, t_list **b, int n, int *x)
{
	unsigned int	i;
	int				j;
	unsigned int	mid;
	(void) x;

	mid = 0;
	(void) j;
	while (ft_lstsize(*a) > 3)
	{
		mid = midpoint(mid, n);
		i = 0;
		j = 0;
		while (i < mid && ft_lstsize(*a) > 3)
		{
			if ((*a)->index < mid)
			{
				push(a, b, 2);
				if ((*b)->index > mid / 2)
				{
					if (on_the_right_side(*a, mid))
						rotate_both(a, b);
					else
						rotate(b, 2);
					j++;
				}
			}
			else if (on_the_right_side(*a, mid))
				rotate(a, 1);
			else
				rrotate(a, 1);
			i++;
		}
		while (j--)
			rrotate(b, 2);
	}
}

void	sorting(t_list **a, t_list **b, int n, int *x)
{
	(void) x;
	(void) b;
	if (n == 2)
	{
		if ((*a)->d > (*a)->n->d)
			swap(a, 1);
	}
	else if (n == 3)
		sort_3(a, 1);
	else if (n >= 4)
	{
		quick_sort(a, b, n, x);
		sort_3(a, 1);
		push(b, a, 1);
		push(b, a, 1);
		sort_3intop(a, 1);
	}
}
