/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:54:22 by tikhacha          #+#    #+#             */
/*   Updated: 2023/04/01 19:15:44 by yourLogin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	lenght;

	lenght = 0;
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	while (lenght < count * size)
	{
		((unsigned char *)pointer)[lenght++] = 0;
	}
	return (pointer);
}
