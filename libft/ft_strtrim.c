/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:33:13 by filferna          #+#    #+#             */
/*   Updated: 2024/04/26 18:45:13 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*trimmed;
	int		len;

	i = 0;
	start = 0;
	len = ft_strlen(str) - 1;
	end = len;
	while (str[start] && char_in_set(str[start], set))
		start++;
	while (end >= start && char_in_set(str[end], set))
		end--;
	trimmed = (char *)malloc((end - start + 2) * sizeof(char));
	if (!trimmed)
		return (NULL);
	while (start <= end)
		trimmed[i++] = str[start++];
	trimmed[i] = '\0';
	return (trimmed);
}
/*
int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char *trimmed = ft_strtrim(" \n\t", " \n\t");
	printf("trimmed: %s", trimmed);
	return (0);
}*/
