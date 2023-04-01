/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:48:58 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/16 19:03:24 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int	ft_lenght(unsigned int n)
{
	int	k;

	k = 0;
	while (n != 0)
	{
		n /= 10;
		k++;
	}
	return (k);
}

static char	ft_chr(unsigned int n, int lenght)
{
	while (--lenght)
		n /= 10;
	n %= 10;
	return (n + '0');
}

char	*ft_itoaun(unsigned int n)
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
