/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nmbs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:10:09 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/16 19:59:19 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr(int nb)
{
	return (ft_putstr(ft_itoa(nb), 1));
}

int	ft_putnbrun(unsigned int nb)
{
	return (ft_putstr(ft_itoaun(nb), 1));
}

int	ft_putnbrhex(unsigned int nb, char c)
{
	return (ft_putstr(ft_itoahex(nb, c), 1));
}

int	ft_putptrhex(char const *ptr)
{
	write (1, "0x", 2);
	return (ft_putstr(ft_itoaptrhex((uintptr_t) ptr), 1) + 2);
}
