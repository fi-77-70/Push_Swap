/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:39:48 by filferna          #+#    #+#             */
/*   Updated: 2024/04/19 01:02:45 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
		((unsigned char *)str)[j++] = c;
	return (str);
}

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	int tamanho = *av[2] - 48;
// 	ft_memset(av[1], '%', tamanho);
// 	printf("%s\n", av[1]);
// 	return (0);
// }