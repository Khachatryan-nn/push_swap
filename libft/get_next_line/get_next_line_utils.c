/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:39:23 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/27 16:45:54 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if ((size_t)start > l)
		return (ft_strdup(""));
	if (len > l)
		len = l;
	p = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!p)
		return (0);
	while (i < len)
	{
		p[i] = *(s + start + i);
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

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
