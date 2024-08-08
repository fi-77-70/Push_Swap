/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:26:34 by filferna          #+#    #+#             */
/*   Updated: 2024/04/24 18:30:14 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;

	if (n <= 0)
		return (0);
	first = (unsigned char *)str1;
	second = (unsigned char *)str2;
	while (--n && *first != '\0' && *second != '\0')
	{
		if (*second != *first)
			return (*first - *second);
		else
		{
			first++;
			second++;
		}
	}
	return (*first - *second);
}

// int main(void)
// {
// 	const char str1[] = "test\200";
// 	const char str2[] = "test\0";

// 	int result = ft_strncmp(str1, str2, -1);
// 	printf("comparisson result: %d\n", result);
// 	return (0);
// }