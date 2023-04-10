/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:44:36 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/09 01:01:12 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3a(t_list **a)
{
	if ((*a)->data > (*a)->next->data && (*a)->next->data > (*a)->next->next->data)
	{
		swap(a);
		rrotate(a);
		printf("sa\nrra\n");
	}
	else if ((*a)->data > (*a)->next->next->data && (*a)->next->data < (*a)->next->next->data)
	{
		rotate(a);
		printf("ra\n");
	}
	else if ((*a)->data > (*a)->next->data && (*a)->data < (*a)->next->next->data)
	{
		swap(a);
		printf("sa\n");
	}
	else if ((*a)->data < (*a)->next->data && (*a)->data > (*a)->next->next->data)
	{
		rrotate(a);
		printf("rra\n");
	}
	else if ((*a)->data < (*a)->next->next->data && (*a)->next->next->data < (*a)->next->data)
	{
		swap(a);
		rotate(a);
		printf("sa\nra\n");
	}
}

void	sort_3b(t_list **b)
{
	if ((*b)->data > (*b)->next->data && (*b)->next->data > (*b)->next->next->data)
	{
		swap(b);
		rrotate(b);
		printf("sb\nrrb\n");
	}
	else if ((*b)->data > (*b)->next->next->data && (*b)->next->data < (*b)->next->next->data)
	{
		rotate(b);
		printf("rb\n");
	}
	else if ((*b)->data > (*b)->next->data && (*b)->data < (*b)->next->next->data)
	{
		swap(b);
		printf("sb\n");
	}
	else if ((*b)->data < (*b)->next->data && (*b)->data > (*b)->next->next->data)
	{
		rrotate(b);
		printf("rrb\n");
	}
	else if ((*b)->data < (*b)->next->next->data && (*b)->next->next->data < (*b)->next->data)
	{
		swap(b);
		rotate(b);
		printf("sb\nrb\n");
	}
}

void	sort_3plus(t_list **a, t_list **b)
{
	push(a, b);
	push(a, b);
	push(a, b);
	//sort_3b(b);
}

void	sorting(t_list **a, t_list **b, int n, int *x)
{
	(void) x;
	(void) b;
	if (n == 2)
	{
		if ((*a)->data > (*a)->next->data)
			swap(a);
	}
	else if (n == 3)
		sort_3a(a);
	else if (n == 4)
		sort_3plus(a, b);
}
