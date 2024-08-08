/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:33:42 by filferna          #+#    #+#             */
/*   Updated: 2024/05/01 21:39:52 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include "ft_printf.h"

int	ft_puthexx(unsigned long a)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (a >= 16)
	{
		count += ft_puthexx(a / 16);
		a = a % 16;
	}
	if (a < 16)
		count += ft_putchar(base[a]);
	return (count);
}
