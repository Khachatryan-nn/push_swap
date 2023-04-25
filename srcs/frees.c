/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:22:21 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/25 20:06:26 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*Does free for a stack only, but in first uses lstclear
*Then does free, and after all, makes a = 0*/
int	free_a(t_list *a)
{
	if (a)
	{
		ft_lstclear(&a);
		free(a);
		a = 0;
	}
	return (0);
}

/*
*Frees 2 lists and integer array, given as arguments,
*then equalizing them to 0 and fter all, returning 0.
*/
int	free_all(t_list **a, t_list **b, int *int_arr)
{
	if (*a)
	{
		ft_lstclear(a);
		free(*a);
		a = 0;
	}
	if (*b)
	{
		ft_lstclear(b);
		free (*b);
		b = 0;
	}
	if (int_arr != NULL)
	{
		free(int_arr);
		int_arr = NULL;
	}
	return (0);
}

/*
*Does just free for two stacks*/
int	free_stacks(t_list **a, t_list **b)
{
	if (a)
	{
		if (ft_lstsize(*a) > 0)
			ft_lstclear(a);
		free(*a);
		a = 0;
	}
	if (b)
	{
		if (ft_lstsize(*b) > 0)
			ft_lstclear(b);
		free (*b);
		b = 0;
	}
	//system("leaks push_swap");
	system("leaks checker");
	ft_printf("Error\n");
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
