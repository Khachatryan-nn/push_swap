/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:44:36 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/11 19:26:54 by tikhacha         ###   ########.fr       */
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
	int				len;
	unsigned int	mid;
	(void) x;

	i = 0;
	len = n;
	mid = 0;
	while (ft_lstsize(a) > 3)
	{
		mid = midpoint(n);
		while (i < mid)
		{
			if ((*a)->index < mid)
			{
				push(a, b, 2);
				i++;
			}
			rotate(a, 1);
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
	else if (n >= 4 && n <= 12)
		quick_sort(a, b, n, x);
}
