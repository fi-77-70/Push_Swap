/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:06:23 by filferna          #+#    #+#             */
/*   Updated: 2024/04/26 19:35:14 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	int		i;
	size_t	size;
	char	*sub;

	i = 0;
	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	if ((ft_strlen(str) - (size_t)start) < len)
		size = ft_strlen(str) - (size_t)start;
	else
		size = len;
	sub = (char *)malloc((size + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while ((unsigned int)ft_strlen(str) > start && len-- > 0)
		sub[i++] = str[start++];
	sub[i] = '\0';
	return (sub);
}
/* 
int main(void)
{
	const char str[] = "hola";
	char *sub = ft_substr(str, 0, 18446744073709551615);
	printf("%s", sub);
	return (0);
} */