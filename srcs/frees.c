/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:22:21 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/06 19:16:50 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*Frees 2 lists and integer array, given as arguments,
*then equalizing them to 0 and fter all, returning 0.
*/
int	free_all(t_list *a, t_list *b, int	*int_arr)
{
	if (a)
		ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
	free(a);
	a = 0;
	free (b);
	b = 0;
	free(int_arr);
	return (0);
}

/*
*Does free() for string, equalizes him to 0
*and returns NULL
*/
char	**free_str(char	*str)
{
	free (str);
	str = 0;
	return (NULL);
}
