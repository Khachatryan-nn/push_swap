/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:52:02 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/06 16:58:56 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	return (x);
}
