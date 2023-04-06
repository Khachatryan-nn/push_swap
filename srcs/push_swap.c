/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:51:39 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/06 19:13:04 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*This function prints the integer data stored in each node of a linked list.
*If the linked list is empty, it prints an error message saying so.
*If the data in a node is NULL, it skips that node and prints
*an error message indicating the data is NULL.*/
void	print_list(t_list *start)
{
	t_list	*ptr;

	if (start == NULL)
	{
		ft_printf("Error: linked list is empty.\n");
		return ;
	}
	ptr = start;
	while (ptr != NULL)
	{
		if (!(ptr->data))
		{
			ft_printf("Error: data is NULL.\n");
			ptr = ptr->next;
			continue ;
		}
		ft_printf("%d\n", (ptr->data));
		ptr = ptr->next;
	}
}

int	main(int argv, char **argc)
{
	t_list	*a;
	t_list	*b;
	int		*int_arr;
	int		len;

	len = 0;
	int_arr = (int *)malloc(sizeof(len));
	a = (t_list *)malloc(sizeof(t_list));
	b = (t_list *)malloc(sizeof(t_list));
	if (!a || !int_arr || !b)
		return (free_all(a, b, int_arr));
	a = fill_a(argv, argc);
	if (!a)
		return (free_all(a, b, int_arr));
	print_list(a);
}
