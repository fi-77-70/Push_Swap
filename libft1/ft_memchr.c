/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:38:14 by filferna          #+#    #+#             */
/*   Updated: 2024/04/26 15:47:45 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (temp[i] == (unsigned char)c && i < n)
			return ((void *)(temp + i));
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	const char str[] = "hello";

	char *ptr = ft_memchr(str, 'l', 5);
	printf("%s\n", ptr);
	return (0);
}*/