/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:07:08 by filferna          #+#    #+#             */
/*   Updated: 2024/04/11 17:05:37 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int	main(int ac, char **av)
{
	int	result;

	if (ac != 2)
		return (1);
	result = ft_isascii(av[1][0]);
	printf("%d", result);
	printf("not ascii %d", ft_isascii(127));
	return (0);
}*/