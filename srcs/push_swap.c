/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:51:39 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/09 00:57:15 by tikhacha         ###   ########.fr       */
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
	a = NULL;
	b = NULL;
	a = fill_a(argv, argc, &len);
	if (!a)
		return (free_stacks(a, b));
	int_arr = fill_int_arr(a, len);
	if (int_arr == NULL)
		return (free_stacks(a, b));
	sorting(&a, &b, len, int_arr);
//	sort_array_buttefly(int_arr, len);
//	print_int_array(int_arr, len);
	ft_printf("list a:\n");
	print_list(a);
	ft_printf("list b:\n");
	print_list(b);
	return(free_a(a));
}
