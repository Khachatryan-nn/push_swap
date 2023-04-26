/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:14:16 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/26 16:20:29 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(const char *str, t_list **a)
{
	int	sign;
	int	counter;

	counter = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		counter *= 10;
		if (sign > 0)
			counter += *str - '0';
		else
			counter -= *str - '0';
		if ((counter > 0 && sign == -1) || (counter < 0 && sign == 1))
			exit(free_a(a));
		str++;
	}
	return (counter);
}
