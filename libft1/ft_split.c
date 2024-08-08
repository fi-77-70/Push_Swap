/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:03:15 by filferna          #+#    #+#             */
/*   Updated: 2024/04/29 17:31:31 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

static char	**ft_clean_matrix(char **matrix, int i)
{
	while (i--)
		free(matrix[i]);
	free(matrix);
	return (NULL);
}

static int	ft_word_count(const char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && str[i])
			words += 1;
		while (str[i] != c && str[i])
			i++;
		while (str[i] == c && str[i])
			i++;
	}
	return (words);
}

static char	**ft_sub_matrix(char **matrix, const char *str, int strs, char sep)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	matrix = (char **)malloc((strs + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	while (i < strs)
	{
		while (str[j] && str[j] == sep)
			j++;
		while (str[j] && str[j] != sep && ++len)
			j++;
		matrix[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!matrix[i])
			return (ft_clean_matrix(matrix, i));
		len = 0;
		i++;
	}
	return (matrix);
}

char	**ft_split(const char *str, char c)
{
	int		words;
	int		i;
	int		j;
	int		a;
	char	**split;

	split = NULL;
	words = ft_word_count(str, c);
	split = ft_sub_matrix(split, str, words, c);
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j != words && split)
	{
		a = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
			split[j][a++] = str[i++];
		split[j++][a] = '\0';
	}
	split[j] = NULL;
	return (split);
}
// int main(int ac, char **av)
// {
// 	(void)ac;
// 	char **str = ft_split(av[1], *av[2]);
// 	int i = 0;
// 	while (str[i])
// 		printf("%s\n", str[i++]);
// 	return (0);
// }