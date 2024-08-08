/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:43:54 by filferna          #+#    #+#             */
/*   Updated: 2024/04/11 16:25:45 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
