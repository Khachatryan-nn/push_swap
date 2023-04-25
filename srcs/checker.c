/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:11:57 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/25 09:26:51 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	read_from_out(t_list **a, t_list **b)
{
	char	*text;

	text = get_next_line(0);
	while (text != NULL)
	{
		if (ft_strcmp(text, "pa\n") == 0)
			push(b, a, 5);
		else if (ft_strcmp(text, "pb\n") == 0)
			push(a, b, 5);
		else if (ft_strcmp(text, "sa\n") == 0)
			swap(a, 5);
		else if (ft_strcmp(text, "sb\n") == 0)
			swap(b, 5);
		else if (ft_strcmp(text, "ra\n") == 0)
			rotate(a, 5);
		else if (ft_strcmp(text, "rb\n") == 0)
			rotate(b, 5);
		else if (ft_strcmp(text, "rra\n") == 0)
			rrotate(a, 5);
		else if (ft_strcmp(text, "rrb\n") == 0)
			rrotate(b, 5);
		else if (ft_strcmp(text, "ss\n") == 0)
			swap_both(a, b, 1);
		else if (ft_strcmp(text, "rr\n") == 0)
			rotate_both(a, b, 1);
		else if (ft_strcmp(text, "rrr\n") == 0)
			rrotate_both(a, b, 1);
		text = get_next_line(0);
	}
}

static void	check(t_list *a)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		i++;
		if (a->d != i)
		{
			write(1, "KO\n", 3);
			return ;
		}
		a = a->n;
	}
	write (1, "OK\n", 3);
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
		return (free_stacks(a, b));int_arr = fill_int_arr(a, len);
	if (int_arr == NULL)
		return (free_stacks(a, b));
	int_arr = fill_int_arr(a, len);
	indexing(a, int_arr, len);
	read_from_out(&a, &b);
	check(a);
	exit(free_all(a, b, int_arr));
}