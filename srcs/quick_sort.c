/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:06:14 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/17 23:26:40 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*This function counting where it's encountered number
*smaller than our mid, then countings the same from
*the end. If i > 1, then it's encountered number
*smaller then our mid, in the left side and returns 0.
*In case if it's on the right side, it's returns 1.
*If start is in range of mid, returns 2.*/
int	otrs(t_list *start, int mid)
{
	int	i;

	i = 0;
	if (start->index < mid && start->index > 2)
		return (2);
	while (start->n)
	{
		if (start->index < mid && start->index > 2)
			break ;
		else
			start = start->n;
		i++;
	}
	while (start->n)
		start = start->n;
	while (start->p)
	{
		if (start->index < mid && start->index > 2)
			break ;
		else
			start = start->p;
		i--;
	}
	if (i > 0)
		return (0);
	return (1);
}

/*
*Search if the largest number with the index LEN
*is on the right side, returns 1. Otherwise return 0.
*If start is the largest, then return 2*/
int	mor(t_list *start, int len)
{
	int	i;

	i = 0;
	if (start->index == len)
		return (2);
	while (start)
	{
		i++;
		if (start->index == len)
			break ;
		start = start->n;
	}
	if (i < len / 2)
		return (1);
	return (0);
}

int	rev_quick_sort(t_list **a, t_list **b, int n)
{
	int	j;
	int	i;
	int	count;

	j = n - 1;
	count = 3;
	i = 0;
	while (j - count >= 0)
	{
		if ((*b)->index == j)
			rev_quick_sort_part_1(a, b, &i, &j);
		else if ((*b)->index == j - i - 1 && i < 3 && j - count > i)
			rev_quick_sort_part_2(a, b, &i, j);
		else if ((*b)->index == count && i <= 1)
			rev_quick_sort_part_3(a, b, j, &count);
		else
			rev_quick_sort_part_4(a, b, j);
	}
	return (count);
}
