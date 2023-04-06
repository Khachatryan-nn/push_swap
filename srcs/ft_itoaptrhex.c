/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaptrhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:58:34 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/06 16:59:16 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_lenght(uintptr_t n)
{
	int	k;

	k = 0;
	while (n != 0)
	{
		n /= 16;
		k++;
	}
	return (k);
}

static char	ft_chr(uintptr_t n, int lenght)
{
	while (--lenght)
		n /= 16;
	n %= 16;
	if (n > 9)
		return (97 + n % 10);
	return (n + '0');
}

char	*ft_itoaptrhex(uintptr_t n)
{
	char	*p;
	int		i;
	int		lenght;

	i = 0;
	if (n == 0)
		lenght = 1;
	else
		lenght = ft_lenght(n);
	p = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!p)
		return (0);
	while (lenght)
		p[i++] = ft_chr(n, lenght--);
	p[i] = '\0';
	return (p);
}
