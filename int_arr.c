/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:52:02 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/03 16:58:40 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_int_arr(t_list	*a, int len)
{
	int	*x;
	int	i;

	x = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len && !a)
	{
		x[i] = (int) a->content;
		i++;
		a = a->next;
	}
	return (x);
}
