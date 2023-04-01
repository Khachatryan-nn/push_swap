/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:13:45 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/02 15:37:17 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (dst == 0 && dstsize == 0)
		return (ft_strlen((char *)src));
	while (dst[i] && i < dstsize)
		i++;
	while (src[n] && dstsize > i + n + 1)
	{
		dst[n + i] = src[n];
		n++;
	}
	if (dstsize > i)
		dst[n + i] = '\0';
	return (i + ft_strlen((char *)src));
}
