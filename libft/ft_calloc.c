/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:14:15 by filferna          #+#    #+#             */
/*   Updated: 2024/04/24 18:32:45 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t			i;
	void			*ptr;
	unsigned char	*zeroing;

	i = n * size;
	ptr = (void *)malloc(n * size);
	if (!ptr)
		return (NULL);
	zeroing = (unsigned char *)ptr;
	while (i-- > 0)
		*zeroing++ = 0;
	return (ptr);
}
/*
int main(void)
{
	int *a;
	int i = 0;

	a = (int *)ft_calloc(3, sizeof(int));
	a[0] = 21;
	a[1] = 7;
	a[2] = 432;
	
	while (a[i])
		printf("%d\n", a[i++]);
	return (0);
}*/