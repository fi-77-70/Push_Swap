/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:12:40 by filferna          #+#    #+#             */
/*   Updated: 2024/08/05 14:11:42 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_all_list(node **stack)
{
	node	*temp;

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

void	ft_newlist(char **arguments, node **stack_a)
{
	int		i;
	node	*list;

	i = 0;
	*stack_a = (node *)malloc(sizeof(node));
	if (!(*stack_a))
		return ;
	(*stack_a)->number = ft_atol(arguments[i++]);
	(*stack_a)->index = -1;
	list = *stack_a;
	while (arguments[i])
	{
		list->next = (node *)malloc(sizeof(node));
		if (!list->next)
		{
			free_all_list(stack_a);
			return ;
		}
		list = list->next;
		list->number = ft_atol(arguments[i]);
		list->index = -1;
		list->next = NULL;
		i++;
	}
	return ;
}

void	ft_swap(char x, node **list_a, node **list_b)
{
	int				temp;
	unsigned int	t_index;

	ft_printf("s%c\n", x); 
	if ((x == 'a' || x == 's') && size_of_list(list_a) >=2)
	{
		t_index = (*list_a)->index;
		temp = (*list_a)->number;
		(*list_a)->number = (*list_a)->next->number;
		(*list_a)->index = (*list_a)->next->index;
		(*list_a)->next->number = temp;
		(*list_a)->next->index = t_index;
	}
	if ((x == 'b' || x == 's') && size_of_list(list_b) >= 2)
	{
		temp = (*list_b)->number;
		(*list_b)->number = (*list_b)->next->number;
		*list_b = (*list_b)->next;
		(*list_b)->number = temp;
	}
	return ;
}

void	ft_index(node **stack_a)
{
	node	*temp;
	int		min;
	int		max;

	temp = *stack_a;
	min = temp->number;
	max = temp->number;
	while(temp)
	{
		if (min > temp->number)
			min = temp->number;
		if (max < temp->number)
			max = temp->number;
		temp = temp->next;
	}
	temp = *stack_a;
	while (temp->number != min)
		temp = temp->next;
	temp->index = 0;
	ft_sort_index(stack_a, 1);
}

void	ft_sort_index(node **stack, unsigned int index)
{
	int		min;
	node	*temp;

	temp = *stack;
	while (temp->index != -1 && temp->next)
		temp = temp->next;
	if (temp->index != -1)
		return ;
	min = temp->number;
	temp = *stack;
	while (temp)
	{
		if(temp->number < min && temp->index == -1)
			min = temp->number;
		temp = temp->next;
	}
	temp = *stack;
	while (temp->number != min)
		temp = temp->next;
	temp->index = index;
	ft_sort_index(stack, ++index);
}
int	ft_max_bits(node **stack)
{
	node	*temp;
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
