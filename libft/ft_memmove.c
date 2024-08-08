/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:45:42 by filferna          #+#    #+#             */
/*   Updated: 2024/04/24 18:38:33 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;

	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (src > dest)
		return (ft_memcpy(pd, ps, n));
	if (src < dest)
	{
		while (n--)
			pd[n] = ps[n];
	}
	return (dest);
}
// int main(int ac, char **av)
// {
// 	char str1[4] = "uma";

// 	if (ac != 4)
// 		return (1);
// 	int tamanho = *av[3] - 48;
// 	printf("original: %s", av[1]);
// 	unsigned char *dest = ft_memmove(av[2], av[1], tamanho);
// 	printf("\n");
// 	printf("destino: %s", dest);
// 	unsigned char *test = ft_memmove(&str1[1], str1, 3);
// 	printf("\n");
// 	printf("test: %s", test);
// 	return (0);
// }