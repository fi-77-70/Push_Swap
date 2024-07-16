/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:12:40 by filferna          #+#    #+#             */
/*   Updated: 2024/07/16 18:21:00 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_all_list(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	if (stack)
		free (stack);
	return (NULL);
}

void	ft_newlist(char **arguments, t_list **stack_a)
{
	int		i;
	t_list	*list;

	i = 1;
	*stack_a = (t_list *)malloc(sizeof(t_list));
	if (!(*stack_a))
		return ;
	(*stack_a)->number = ft_atoi(arguments[i++]);
	(*stack_a)->next = NULL;
	list = *stack_a;
	while (arguments[i])
	{
		list->next = (t_list *)malloc(sizeof(t_list));
		if (!list->next)
		{
			free_all_list(stack_a);
			return ;
		}
		list = list->next;
		list->number = ft_atoi(arguments[i]);
		list->next = NULL;
		i++;
	}
	return ;
}

void	ft_swap(char x, t_list **list_a, t_list **list_b)
{
	int	temp;

	write(1, "s", 1);
	write(1, &x, 1);
	write(1, "\n", 1);
	if (x == 's' && (*list_a)->next->number && (*list_b)->next->number)
	{
		ft_swap('a', list_a, list_b);
		ft_swap('b', list_a, list_b);
		return ;
	}
	else if (x == 'a' && (*list_a)->next->number)
	{
		temp = (*list_a)->number;
		(*list_a)->number = (*list_a)->next->number;
		(*list_a)->next->number = temp;
	}
	else if (x == 'b' && (*list_b)->next->number)
	{
		temp = (*list_b)->number;
		(*list_b)->number = (*list_b)->next->number;
		*list_b = (*list_b)->next;
		(*list_b)->number = temp;
	}
	return ;
}

int	ft_atoi(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	i = 0;
	sign = 1;
	while (!(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
