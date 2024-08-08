/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:27:12 by filferna          #+#    #+#             */
/*   Updated: 2024/04/24 21:22:34 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	int		i;
	int		j;
	size_t	result;

	if ((int)n == 0)
		return (ft_strlen(src));
	result = (size_t)ft_strlen(src) + (size_t)ft_strlen(dest);
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && (size_t)i < (n - 1))
		dest[i++] = src[j++];
	dest[i] = '\0';
	if (n < (size_t)ft_strlen(dest))
		return ((size_t)ft_strlen(src) + n);
	return (result);
}

// int	main(void)
// {
// 	char dest[] = "rrrrrrrrrrrrrrr";

// 	int return_value = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
// 	printf("ft_strlcat: %d - %s\n", return_value, dest);
// 	return (0);
// }