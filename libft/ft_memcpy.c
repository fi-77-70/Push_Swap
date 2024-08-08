/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:38:58 by filferna          #+#    #+#             */
/*   Updated: 2024/04/24 18:39:07 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <unistd.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;
	size_t			x;

	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	if (!pd && !ps)
		return (0);
	x = 0;
	while (x < n)
	{
		pd[x] = ps[x];
		x++;
	}
	return (dest);
}
/*
int main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	int tamanho = *av[3] - 48;
	printf("original: %s", av[1]);
	unsigned char *dest = ft_memcpy(av[2], av[1], tamanho);
	printf("\n");
	printf("destino: %s", dest);
	return (0);
}*/