/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:11:18 by filferna          #+#    #+#             */
/*   Updated: 2024/08/05 18:35:40 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (result * sign);
}

int	int_size(node **stack)
{
	node	*temp;
	node	*dup;

	temp = *stack;
	while (temp)
	{
		if (temp->number < MIN_INT || temp->number > MAX_INT)
			return (ft_printf("ERROR\n"));
		temp = temp->next;
	}
	dup = *stack;
	while (dup->next)
	{
		temp = dup->next;
		while (temp)
		{
			if (dup->number == temp->number)
				return (ft_printf("ERROR\n"));
			else
				temp = temp->next;
		}
		dup = dup->next;
	}
	return (0);
}
int	get_min(node **stack)
{
	node 	*temp;
	int		min;

	temp = *stack;
	min = temp->number;
	while (temp)
	{
		if (temp->number < min)
			min = temp->number;
		temp = temp->next;
	}
	return (min);
}

void	ft_clean_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return ;
}
