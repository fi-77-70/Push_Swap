/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:22:09 by filferna          #+#    #+#             */
/*   Updated: 2024/08/02 14:29:45 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_two(node **stack_b)
{
	node	*first;
	node	*temp;

	first = (*stack_b)->next;
	temp = *stack_b;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = temp;
	*stack_b = (*stack_b)->next;
	(*stack_b)->next = NULL;
	*stack_b = first;
	return ;
}

static void	reverse_two(node **stack_b)
{
	node	*first;
	node	*temp;

	first = *stack_b;
	while ((*stack_b)->next->next)
		*stack_b = (*stack_b)->next;
	temp = (*stack_b)->next;
	(*stack_b)->next = NULL;
	*stack_b = temp;
	(*stack_b)->next = first;
	return ;
}

void	ft_reverse_rotate(char x, node **stack_a, node **stack_b)
{
	node	*temp;
	node	*first;

	ft_printf("rr%c\n", x);
	if ((x == 'a' || x == 'r') && *stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		while ((*stack_a)->next->next)
			*stack_a = (*stack_a)->next;
		temp = (*stack_a)->next;
		(*stack_a)->next = NULL;
		*stack_a = temp;
		(*stack_a)->next = first;
	}
	if ((x == 'r' || x == 'b') && *stack_b && (*stack_b)->next)
		reverse_two(stack_b);
	return ;
}

void	ft_rotate(char x, node **stack_a, node **stack_b)
{
	node	*temp;
	node	*first;

	ft_printf("r%c\n", x);
	if ((x == 'a' || x == 'r') && (*stack_a) && (*stack_a)->next)
	{
		first = (*stack_a)->next;
		temp = *stack_a;
		while ((*stack_a)->next)
			*stack_a = (*stack_a)->next;
		(*stack_a)->next = temp;
		*stack_a = (*stack_a)->next;
		(*stack_a)->next = NULL;
		*stack_a = first;
	}
	if ((x == 'b' || x == 'r') && (*stack_b) && (*stack_b)->next)
		rotate_two(stack_b);
	return ;
}

void	ft_push(char x, node **stack_from, node **stack_to)
{
	node	*list_push;
	node	*list_receive;
	node	*temp;

	if (!stack_from || !(*stack_from))
		return ;
	ft_printf("p%c\n", x);
	list_push = *stack_from;
	list_receive = *stack_to;
	temp = list_push->next;
	if (!list_receive)
	{
		list_push->next = NULL;
		list_receive = list_push;
		*stack_to = list_push;
		*stack_from = temp;
	}
	else
	{
		list_push->next = list_receive;
		list_receive = list_push;
		*stack_to = list_push;
		*stack_from = temp;
	}
	return ;
}
