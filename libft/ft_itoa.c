/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:29:31 by filferna          #+#    #+#             */
/*   Updated: 2024/04/24 19:44:07 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_len(int n)
{
	int	len;

	len = 1;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_translate(char *str, long n, int len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = n * -1;
	}
	str[len--] = '\0';
	while (n > 9)
	{
		str[len--] = (n % 10) + 48;
		n = n / 10;
	}
	str[len] = (n % 10) + 48;
	return ;
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	long	i;

	i = n;
	len = ft_len(n);
	if (n < 0)
	{
		result = (char *)malloc(len * sizeof(char) + 2);
		if (!result)
			return (NULL);
		ft_translate(result, i, len + 1);
	}
	else
	{
		result = (char *)malloc(len * sizeof(char) + 1);
		if (!result)
			return (NULL);
		ft_translate(result, i, len);
	}
	return (result);
}

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	char *result = ft_itoa(ft_atoi(av[1]));
// 	printf("result: %s", result);
// 	if (result)
// 		free(result);
// 	return(0);
// }