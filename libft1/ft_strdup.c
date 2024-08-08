/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:33:09 by filferna          #+#    #+#             */
/*   Updated: 2024/04/24 18:42:33 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		counter;
	char	*dup;

	counter = 0;
	while (str[counter])
		counter++;
	dup = (char *)malloc((counter + 1) * sizeof(char));
	if (!dup)
		return (0);
	counter = 0;
	while (str[counter])
	{
		dup[counter] = str[counter];
		counter++;
	}
	dup[counter] = '\0';
	return (dup);
}
/*
int main(void)
{
	const char str[] = "hello";
	char *dup = ft_strdup(str);
	printf("%s", dup);
	free(dup);
	return (0);
}*/