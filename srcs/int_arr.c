/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:52:02 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/26 17:22:06 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	unique(int *x, int n)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (i != j && x[i] == x[j])
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	sorted(int *x, int n)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < n)
	{
		if (i < n && x[i - 1] > x[i] && i > 0)
			check = 1;
		i++;
	}
	if (check == 0)
		return (1);
	else
		return (0);
}

/*
 * This function allocates memory for integers array
 * then checks d in our lists and inserts them in array
 * After that returning array */
int	*fill_int_arr(t_list *a, int len)
{
	int	*x;
	int	i;

	x = (int *)malloc(sizeof(int) * len);
	if (!x)
		return (NULL);
	i = 0;
	while (i < len && a != NULL)
	{
		x[i] = a->d;
		i++;
		a = a->n;
	}
	if (!unique(x, len))
	{
		free(x);
		return (NULL);
	}
	return (x);
}

static void	swap_ints(int *sw1, int *sw2)
{
	int	temp;

	temp = *sw1;
	*sw1 = *sw2;
	*sw2 = temp;
}

void	sort_int_arr(int *x, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len)
	{
		temp = i;
		j = i;
		while (j < len)
		{
			if (x[j] < x[temp])
				temp = j;
			j++;
		}
		swap_ints(&x[i], &x[temp]);
		i++;
	}
}
