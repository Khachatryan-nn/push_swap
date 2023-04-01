/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:47:31 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/10 18:40:07 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char		*p;
	int			i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (p == NULL)
		return (NULL);
	while (s1[i])
	{
		p[i] = (char) s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
