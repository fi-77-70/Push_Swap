/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:13:40 by filferna          #+#    #+#             */
/*   Updated: 2024/08/19 14:13:50 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **stack_a, t_node **stack_b)
{
	ft_swap('a', stack_a, stack_b);
	return ;
}

void	sort_3(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	temp = *stack_a;
	if (temp->number > temp->next->number
		&& temp->number > temp->next->next->number)
		ft_rotate('a', stack_a, stack_b);
	else if (temp->next->number > temp->number
		&& temp->next->number > temp->next->next->number)
		ft_reverse_rotate('a', stack_a, stack_b);
	if ((*stack_a)->number > (*stack_a)->next->number)
		ft_swap('a', stack_a, stack_b);
	return ;
}

void	sort_4(t_node **stack_a, t_node **stack_b)
{
	int	min;

	min = get_min(stack_a);
	if ((*stack_a)->next->next->next->number == min)
		ft_reverse_rotate('a', stack_a, stack_b);
	while ((*stack_a)->number != min)
		ft_rotate('a', stack_a, stack_b);
	ft_push('b', stack_a, stack_b);
	sort_3(stack_a, stack_b);
	return (ft_push('a', stack_b, stack_a));
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int		min;

	min = get_min(stack_a);
	if ((*stack_a)->next->next->next->next->index == 0
		|| (*stack_a)->next->next->next->index == 0)
	{
		while ((*stack_a)->number != min)
			ft_reverse_rotate('a', stack_a, stack_b);
	}
	else
	{
		while ((*stack_a)->number != min)
			ft_rotate('a', stack_a, stack_b);
	}
	ft_push('b', stack_a, stack_b);
	sort_4(stack_a, stack_b);
	return (ft_push('a', stack_b, stack_a));
}

void	small(t_node **stack_a, t_node **stack_b)
{
	unsigned int	stack_size;

	if (ft_sorted(stack_a))
		return ;
	stack_size = size_of_list(stack_a) + 1;
	if (stack_size == 2)
		sort_2(stack_a, stack_b);
	else if (stack_size == 3)
		sort_3(stack_a, stack_b);
	else if (stack_size == 4)
		sort_4(stack_a, stack_b);
	else if (stack_size == 5)
		sort_5(stack_a, stack_b);
}
