/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:09:57 by tikhacha          #+#    #+#             */
/*   Updated: 2023/01/27 18:26:59 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p;

	if (!dst && !src)
		return (NULL);
	p = (char *) dst;
	while (n--)
	{
		*p = *(char *) src;
		p++;
		src++;
	}
	return (dst);
}
