/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:58:03 by filferna          #+#    #+#             */
/*   Updated: 2024/05/01 21:39:43 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include "ft_printf.h"

int	ft_putptr(unsigned long a, int i)
{
	int			count;
	char const	*base;

	if (a == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	base = "0123456789abcdef";
	count = 0;
	if (i == 0)
	{
		count = 2;
		write(1, "0x", 2);
	}
	if (a >= 16)
	{
		count += ft_putptr(a / 16, 1);
		a = a % 16;
	}
	if (a < 16)
		count += ft_putchar(base[a]);
	return (count);
}
