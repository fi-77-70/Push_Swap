/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:24:09 by filferna          #+#    #+#             */
/*   Updated: 2024/05/01 21:40:10 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int	ft_putudten(unsigned int d);
int	ft_puthexx(unsigned long a);
int	ft_puthex(unsigned int a);
int	ft_putptr(unsigned long a, int i);
int	ft_putnbr(int d);
int	ft_putstr(const char *s);
int	ft_putchar(char c);
int	ft_printf(const char *s, ...);

#endif
