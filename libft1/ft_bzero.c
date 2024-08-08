/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:08:51 by filferna          #+#    #+#             */
/*   Updated: 2024/04/11 16:21:19 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include<unistd.h>
#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
		((unsigned char *)str)[j++] = '\0';
}
/*
int main(int ac, char **av)
{
	int x = 0;
	int tamanho = *av[2] - 48;
	if (ac != 3)
		return (1);
	ft_bzero(av[1], tamanho);
	tamanho += 1;
	while(av[1][x] == '\0')
	{
		write(1, "null", 4);
		write(1, " ", 1);
		x++;
	}
	while (av[1][x])
		write(1, &av[1][x++], 1);
	return (0);
}*/