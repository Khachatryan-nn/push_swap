/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:50:46 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/16 18:49:18 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_putchr(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s, int t)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)", 0));
	while (s[i] != '\0')
		ft_putchr(s[i++]);
	if (t == 1)
	{
		free(s);
		s = 0;
	}
	return (i);
}
