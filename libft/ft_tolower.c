/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:58:50 by filferna          #+#    #+#             */
/*   Updated: 2024/04/26 19:38:30 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
int	main(void)
{
	char a = ft_tolower('F');
	char b = ft_tolower('z');
	char c = ft_tolower('2');

	printf("%c\n", a);
	printf("%c\n", b);
	printf("%c\n", c);
	return (0);
}*/