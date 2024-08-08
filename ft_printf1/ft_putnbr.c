/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:45:57 by filferna          #+#    #+#             */
/*   Updated: 2024/05/01 21:39:47 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include "ft_printf.h"

int	ft_putnbr(int d)
{
	long	a;
	int		count;

	a = d;
	count = 0;
	if (a < 0)
	{
		write(1, "-", 1);
		count += 1;
		a = a * -1;
	}
	if (a > 9)
	{
		count += ft_putnbr(a / 10);
		a = a % 10;
	}
	if (a <= 9)
		count += ft_putchar(a + 48);
	return (count);
}
