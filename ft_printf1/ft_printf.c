/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:06:36 by filferna          #+#    #+#             */
/*   Updated: 2024/05/13 21:46:49 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

static int	put_format(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar((va_arg(ap, int)));
	else if (c == 's')
		count = ft_putstr((va_arg(ap, char *)));
	else if (c == 'p')
		count = ft_putptr((va_arg(ap, unsigned long)), 0);
	else if (c == 'd' || c == 'i')
		count = ft_putnbr((va_arg(ap, int)));
	else if (c == 'u')
		count = ft_putudten((va_arg(ap, int)));
	else if (c == 'x')
		count = ft_puthex((va_arg(ap, unsigned int)));
	else if (c == 'X')
		count = ft_puthexx((va_arg(ap, unsigned int)));
	else if (c == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		result;
	va_list	ap;

	result = 0;
	va_start(ap, s);
	while (*s != '\0')
	{
		while (*s != '%' && *s != '\0')
			result += write(1, s++, 1);
		if (*s != '\0' && ++s)
			result += put_format(*(s++), ap);
	}
	va_end(ap);
	return (result);
}
