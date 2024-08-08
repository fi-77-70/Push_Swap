/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:47:31 by filferna          #+#    #+#             */
/*   Updated: 2024/04/24 19:25:45 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;

	if (n <= 0)
		return (0);
	first = (unsigned char *)str1;
	second = (unsigned char *)str2;
	while (*first == *second && --n)
	{
		first++;
		second++;
	}
	return (*first - *second);
}
/*
int main(void)
{
	const char str1[] = "hello";
	const char str2[] = "hello";
	const char str3[] = "hella";

	int igual = ft_memcmp(str1, str2, 5);
	int different = ft_memcmp(str1, str3, 5);
	printf("igual %d\n", igual);
	printf("different %d\n", different);
	return (0);
}*/