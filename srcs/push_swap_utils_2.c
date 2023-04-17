/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:54:22 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/17 10:18:55 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting_for_large(t_list **a, t_list **b, int n)
{
	int	count;

	if (n > 100)
		quick_sort(a, b, n, 9);
	else
		quick_sort(a, b, n, 4);
	sort_3(a, 1);
	count = rev_quick_sort(a, b, n);
	while (count--)
		rrotate(a, 1);
	sort_3intop(a, 1);
}

void	indexing(t_list *a, int *x, int len)
{
	int		i;
	t_list	*ptr;

	ptr = a;
	while (ptr)
	{
		i = 0;
		while (i < len && ptr->d != x[i])
			i++;
		ptr->index = i;
		ptr = ptr->n;
	}
}

/*
 * Fills A with string matrix, gived as arg then returns address of first node
 * created by those arguments and lenght of list also*/
t_list	*fill_a(int argv, char **argc, int *len)
{
	t_list	*start;
	char	**args;
	int		i;

	i = 0;
	start = NULL;
	args = spliter(argv, argc);
	if (args == NULL)
		return (start);
	while (args[i] != NULL)
	{
		ft_lstadd_back(&start, ft_lstnew(ft_atoi(args[i])));
		i++;
	}
	*len = i;
	return (start);
}

void	rotate_both(t_list **a, t_list **b)
{
	rotate(a, 3);
	rotate(b, 3);
	write (1, "rr\n", 3);
}

void	rrotate_both(t_list **a, t_list **b)
{
	rrotate(a, 3);
	rrotate(b, 3);
	write (1, "rrr\n", 4);
}