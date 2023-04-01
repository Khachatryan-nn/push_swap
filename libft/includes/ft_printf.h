/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:19:13 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/20 15:07:34 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *arg, ...);
int	ft_percentage(char type, va_list arg);
int	ft_putchr(char c);
int	ft_putstr(char *s, int t);
int	ft_putnbr(int nb);
int	ft_putnbrun(unsigned int nb);
int	ft_putnbrhex(unsigned int nb, char c);
int	ft_putptrhex(char const *ptr);

#endif