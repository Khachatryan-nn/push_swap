/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:15:33 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/06 16:58:56 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char) c == *s)
			return ((char *)s);
		s++;
	}
	if ((char) c == *s)
		return ((char *)s);
	return (NULL);
}
