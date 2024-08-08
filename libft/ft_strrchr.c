/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:46:30 by filferna          #+#    #+#             */
/*   Updated: 2024/04/24 19:38:35 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*temp;

	temp = (char *)str;
	while (*temp)
		temp++;
	while (*temp != (char)c && temp != str)
		temp--;
	if (*temp == (char)c)
		return (temp);
	return (NULL);
}

// int main(void)
// {
// 	const char str[] = "hello world";

// 	char *ptr = ft_strrchr(str, 'z');
// 	printf("%s\n", ptr);
// 	return (0);
// }