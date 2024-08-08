/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:52:30 by filferna          #+#    #+#             */
/*   Updated: 2024/04/26 19:43:09 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/* int main(void)
{
	char a = 128;
	char b = 'G';
	char c = '2';

	int d = ft_toupper(128);
	char e = ft_toupper(b);
	char f = ft_toupper(c);
	printf("%d\n", d);
	printf("%c\n", e);
	printf("%c\n", f);
	return (0);
} */