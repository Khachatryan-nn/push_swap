/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:51:39 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/07 15:30:58 by tikhacha         ###   ########.fr       */
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
	b = (t_list *)malloc(sizeof(t_list));
	if (!b)
		return (free_stacks(a, b));
	a = fill_a(argv, argc, &len);
	if (!a)
		return (free_stacks(a, b));
	int_arr = fill_int_arr(a, len);
	if (int_arr == NULL)
		return (free_stacks(a, b));
	//rotate(&a);
	//free_all(a, b, int_arr);
//	start_sorting(a, b, int_arr, len);
//	sort_array_buttefly(int_arr, len);
//	print_int_array(int_arr, len);
	return(free_a(a));
}
