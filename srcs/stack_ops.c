/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:50:54 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/06 19:28:50 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		return (NULL);
	while (args[i] != NULL)
	{
		ft_lstadd_back(&start, ft_lstnew(ft_atoi(args[i])));
		i++;
	}
	*len = i;
	return (start);
}

/*
* Function swaps the data and index of the first two elements
*of a linked list pointed to by start. If the size of the
*linked list is less than or equal to 1, no action is taken.*/
void	swap(t_list **start)
{
	int	temp_data;
	int	temp_index;

	if (ft_lstsize(*start) > 1)
	{
		temp_data = (*start)->data;
		temp_index = (*start)->index;
		(*start)->data = (*start)->next->data;
		(*start)->index = (*start)->next->index;
		(*start)->next->data = temp_data;
		(*start)->next->index = temp_index;
	}
	return ;
}

/*
 * Pushing first element
 * of list a to list b*/
void	pushb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!a || !*a || !b)
		return ;
	temp = (*a)->next;
	if (!(*b)->data)
	{
		*b = (t_list *)malloc(sizeof(t_list));
		if (!*b)
			return ;
		*b = *a;
		(*b)->next = NULL;
		printf("B was NULL\n");
	}
	else
	{
		(*a)->next = *b;
		(*b)->prev = *a;
		*b = *a;
		printf("B wasn't NULL\n");
	}
	*a = temp;
	(*a)->prev = 0;
	return ;
}
