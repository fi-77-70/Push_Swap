/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:11:18 by filferna          #+#    #+#             */
/*   Updated: 2024/08/19 14:10:06 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
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

int	int_size(t_node **stack)
{
	t_node	*temp;
	t_node	*dup;

	temp = *stack;
	while (temp)
	{
		if (temp->number < MIN_INT || temp->number > 2147483647)
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

int	get_min(t_node **stack)
{
	t_node		*temp;
	int			min;

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

int	ft_clean_matrix(char **matrix, int ac)
{
	int	i;

	if (ac > 2)
		return (0);
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (0);
}

int	ft_max_bits(t_node **stack)
{
	t_node	*temp;
	int		max;
	int		bits;

	temp = *stack;
	max = temp->index;
	bits = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
