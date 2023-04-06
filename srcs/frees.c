/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:22:21 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/06 18:50:45 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*Does free() for all the arguments
*and equalizes them to 0
*/
int	free_all(t_list *a, t_list *b, int	*int_arr)
{
	free(a);
	free(b);
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
