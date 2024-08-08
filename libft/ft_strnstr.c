/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:57:21 by filferna          #+#    #+#             */
/*   Updated: 2024/04/25 21:01:24 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *sub, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*sub)
		return ((char *)big);
	while (big[i] && i < n)
	{
		while (big[i + j] == sub[j] && sub[j] && big[i + j] && (i + j) < n)
			j++;
		if (sub[j] == '\0')
			return ((char *)big + i);
		j = 0;
		i++;
	}
	return (NULL);
}

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	printf("mine: %s", ft_strnstr(av[1], av[2], ft_atoi(av[3])));
// 	return (0);
// }
