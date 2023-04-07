/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:44:36 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/07 18:33:09 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_list **a)
{
	if ((*a)->data > (*a)->next->data && (*a)->next->data > (*a)->next->next->data)
	{
		swap_a(a);
		rrotate_a(a);
	}
	else if ((*a)->data > (*a)->next->next->data && (*a)->next->data < (*a)->next->next->data)
		rotate_a(a);
	else if ((*a)->data > (*a)->next->data && (*a)->data < (*a)->next->next->data)
		swap_a(a);
	else if ((*a)->data < (*a)->next->data && (*a)->data > (*a)->next->next->data)
		rrotate_a(a);
	else if ((*a)->data < (*a)->next->next->data && (*a)->next->next->data < (*a)->next->data)
	{
		swap_a(a);
		rotate_a(a);
	}
}

void	sort_3plus(t_list **a, t_list **b)
{
	push_b(a, b);
	push_b(a, b);
	push_b(a, b);
	push_b(a, b);
	sort_3(b);
	push_a(a, b);
	push_a(a, b);
	push_a(a, b);
}

void	sorting(t_list **a, t_list **b, int n, int *x)
{
	(void) x;
	(void) b;
	if (n == 2)
	{
		if ((*a)->data > (*a)->next->data)
			swap_a(a);
	}
	else if (n == 3)
		sort_3(a);
	else if (n == 4)
		sort_3plus(a, b);
}
