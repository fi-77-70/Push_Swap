/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:32:47 by filferna          #+#    #+#             */
/*   Updated: 2024/05/01 21:39:57 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include "ft_printf.h"

int	ft_puthex(unsigned int a)
{
	int			count;
	char const	*base;

	count = 0;
	base = "0123456789abcdef";
	if (a >= 16)
	{
		count += ft_puthex(a / 16);
		a = a % 16;
	}
	if (a < 16)
		count += ft_putchar(base[a]);
	return (count);
}
