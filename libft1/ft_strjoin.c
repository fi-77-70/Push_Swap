/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:33:51 by filferna          #+#    #+#             */
/*   Updated: 2024/04/24 18:44:09 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	int		i;
	int		j;
	char	*joined;

	i = 0;
	j = 0;
	while (str1[i])
		i++;
	while (str2[j])
		j++;
	joined = (char *)malloc((i + j + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
	{
		joined[i] = str1[i];
		i++;
	}
	while (str2[j])
		joined[i++] = str2[j++];
	joined[i] = '\0';
	return (joined);
}
/*
int main(void)
{
	const char str1[] = "hello";
	const char str2[] = " world";
	char *joined = ft_strjoin(str1, str2);
	printf("joined: %s", joined);
	return (0);
}*/