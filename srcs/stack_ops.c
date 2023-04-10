/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:50:54 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/09 00:53:18 by tikhacha         ###   ########.fr       */
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
		return (start);
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
void	push(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!a || !*a || !b)
		return ;
	if (ft_lstsize(*a) > 0)
	{
		temp = (*a)->next;
		if (ft_lstsize(*b) >= 1)
		{
			(*b)->prev = *a;
			(*a)->next = *b;
			*b = *a;
		}
		else
		{
			(*b) = (t_list *)malloc(sizeof(t_list));
			if (!*b)
				return ;
			*b = *a;
			(*b)->next = NULL;
		}
		(*a) = temp;
		if (*a)
			(*a)->prev = NULL;
	}
	return ;
}

void	rotate(t_list **nodes)
{
	t_list	*temp;

	temp = *nodes;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *nodes;
	temp->next->prev = temp;
	(*nodes)->next->prev = NULL;
	temp = (*nodes)->next;
	temp->prev = NULL;
	(*nodes)->next = NULL;
	*nodes = temp;
	ft_printf("ra\n");
}

void	rrotate(t_list **nodes)
{
	t_list	*temp;

	temp = *nodes;
	while (temp->next != NULL)
		temp = temp->next;
	(*nodes)->prev = temp;
	temp->next = *nodes;
	temp->prev->next = NULL;
	temp->prev = NULL;
	*nodes = temp;
	ft_printf("rra\n");
}