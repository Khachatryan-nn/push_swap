/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:50:54 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/13 18:30:36 by tikhacha         ###   ########.fr       */
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
* Function swaps the d and index of the first two elements
*of a linked list pointed to by start. If the size of the
*linked list is less than or equal to 1, no action is taken.*/
void	swap(t_list **start, int n)
{
	int	temp_d;
	int	temp_index;

	if (ft_lstsize(*start) > 1)
	{
		temp_d = (*start)->d;
		temp_index = (*start)->index;
		(*start)->d = (*start)->n->d;
		(*start)->index = (*start)->n->index;
		(*start)->n->d = temp_d;
		(*start)->n->index = temp_index;
	}
	if (n == 1)
		write(1, "sa\n", 4);
	else if (n == 2)
		write(1, "sb\n", 4);
}

/*
 * Pushing first element
 * of list a to list b*/
void	push(t_list **a, t_list **b, int n)
{
	t_list	*temp;

	if (ft_lstsize(*a) > 0)
	{
		temp = (*a)->n;
		if (ft_lstsize(*b) >= 1)
		{
			(*b)->p = *a;
			(*a)->n = *b;
			*b = *a;
		}
		else
		{
			*b = *a;
			(*b)->n = NULL;
		}
		(*a) = temp;
		if (*a)
			(*a)->p = NULL;
	}
	if (n == 1)
		write(1, "pa\n", 4);
	else
		write(1, "pb\n", 4);
}

void	rotate(t_list **nodes, int n)
{
	t_list	*temp;

	temp = *nodes;
	while (temp->n != NULL)
		temp = temp->n;
	temp->n = *nodes;
	temp->n->p = temp;
	(*nodes)->n->p = NULL;
	temp = (*nodes)->n;
	temp->p = NULL;
	(*nodes)->n = NULL;
	*nodes = temp;
	if (n == 1)
		write(1, "ra\n", 3);
	else if (n == 2)
		write(1, "rb\n", 3);
}

void	rrotate(t_list **nodes, int n)
{
	t_list	*temp;

	temp = *nodes;
	while (temp->n != NULL)
		temp = temp->n;
	(*nodes)->p = temp;
	temp->n = *nodes;
	temp->p->n = NULL;
	temp->p = NULL;
	*nodes = temp;
	if (n == 1)
		write(1, "rra\n", 4);
	else if (n == 2)
		write(1, "rrb\n", 4);
}

void	rotate_both(t_list **a, t_list **b)
{
	rotate(a, 3);
	rotate(b, 3);
	write (1, "rr\n", 3);
}

void	swap_both(t_list **a, t_list **b)
{
	swap(a, 3);
	swap(b, 3);
	write (1, "ss\n", 3);
}
