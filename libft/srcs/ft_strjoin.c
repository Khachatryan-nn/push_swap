/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:22:04 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/10 18:39:20 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		n;
	int		i;
	char	*p;

	if (!s1 || !s2)
		return (0);
	i = 0;
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(sizeof(char) * n);
	if (!p)
		return (NULL);
	while (i < n)
	{
		if (*s1)
			p[i] = *s1++;
		else if (*s2)
			p[i] = *s2++;
		i++;
	}
	p[i - 1] = '\0';
	return (p);
}
