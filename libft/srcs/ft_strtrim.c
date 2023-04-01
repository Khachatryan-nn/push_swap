/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:28:30 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/10 18:58:31 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_find(const char *set, const char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	if (!s1 || !set)
		return (0);
	i = 0;
	k = 0;
	j = ft_strlen((char *)s1) - 1;
	while (s1[i] && ft_find(set, s1[i]))
		i++;
	while (ft_find(set, s1[j]) && i < j)
		j--;
	ptr = (char *)malloc(j - i + 2);
	if (!ptr)
		return (0);
	while (k < j - i + 1)
	{
		ptr[k] = s1[k + i];
		k++;
	}
	ptr[k] = '\0';
	return (ptr);
}
