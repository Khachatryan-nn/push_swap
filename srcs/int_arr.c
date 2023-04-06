/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:52:02 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/06 22:45:45 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_for_reccurence_and_being_sorted(int *x, int n)
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
				return (0);
			j++;
		}
		i++;
		if (i < n && x[i - 1] > x[i])
			check = 1;
	}
	if (!check)
		return (0);
	return (1);
}

/*
 * This function allocates memory for integers array
 * then checks data in our lists and inserts them in array
 * After that returning array */
int	*fill_int_arr(t_list *a, int len)
{
	int	*x;
	int	i;

	x = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len && a != NULL)
	{
		x[i] = a->data;
		i++;
		a = a->next;
	}
	if (!check_for_reccurence_and_being_sorted(x, len))
		return (NULL);
	return (x);
}

void	print_int_array(int *x, int n)
{
	int	i;

	i = 0;
	while (i < n)
		ft_printf("%d\n", x[i++]);
}

static void	swap_ints(int *sw1, int *sw2)
{
	int	temp;

	temp = *sw1;
	*sw1 = *sw2;
	*sw2 = temp;
	ft_printf("sa\n");
}

void	sort_array_buttefly(int	*x, int	len)
{
	int	i;
	int k;
	int	level;
	int	m;

	i = 0;
	k = 2;
	level = len / 2;
	while (k)
	{
		while (i < len - level)
		{
			if (x[i] > x[i + level])
				swap_ints(&x[i], &x[i + level]);
			i++;
		}
		m = len / k;
		i = m;
		while (i >= len)
		{
			i--;
			if (x[i] < x[i - level])
				swap_ints(&x[i], &x[i - level]);
		}
		i = len / 2;
		k--;
	}
	if (level > 0)
		sort_array_buttefly(x, level);
}
/*
void	sort_array_bitonic(int *x, int len)
{
	int	i;
	int	j;

	i = len / 2;
}*/