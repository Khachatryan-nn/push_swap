/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:47:31 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/06 18:58:41 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*This is a function that takes a string as input, allocates memory
*for a new string of the same size, copies the original string to
*the new memory location, and returns a pointer to the new string.
*If the allocation fails, it returns NULL.*/
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
