/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:22:09 by filferna          #+#    #+#             */
/*   Updated: 2024/07/17 15:32:52 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_two(t_list **stack_b)
{
	t_list	*first;
	t_list	*temp;

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

static void	reverse_two(t_list **stack_b)
{
	t_list	*first;
	t_list	*temp;

	first = *stack_b;
	while ((*stack_b)->next->next)
		*stack_b = (*stack_b)->next;
	temp = (*stack_b)->next;
	(*stack_b)->next = NULL;
	*stack_b = temp;
	(*stack_b)->next = first;
	return ;
}

void	ft_reverse_rotate(char x, t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*first;

	write(1, "rr", 2);
	write(1, &x, 1);
	write(1, "\n", 1);
	if (x == 'a' && *stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		while ((*stack_a)->next->next)
			*stack_a = (*stack_a)->next;
		temp = (*stack_a)->next;
		(*stack_a)->next = NULL;
		*stack_a = temp;
		(*stack_a)->next = first;
	}
	else if (x == 'b' && *stack_b && (*stack_b)->next)
		reverse_two(stack_b);
	else if (x == 'r')
	{
		ft_reverse_rotate('a', stack_a, stack_b);
		ft_reverse_rotate('b', stack_a, stack_b);
	}
	return ;
}

void	ft_rotate(char x, t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*first;

	write(1, "r", 1);
	write(1, &x, 1);
	write(1, "\n", 1);
	if (x == 'a' && (*stack_a) && (*stack_a)->next)
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
	else if (x == 'b' && (*stack_b) && (*stack_b)->next)
		rotate_two(stack_b);
	else if (x == 'r')
	{
		ft_rotate('a', stack_a, stack_b);
		ft_rotate('b', stack_a, stack_b);
	}
	return ;
}

void	ft_push(char x, t_list **stack_from, t_list **stack_to)
{
	t_list	*list_push;
	t_list	*list_receive;
	t_list	*temp;

	write(1, "p", 1);
	write(1, &x, 1);
	write(1, "\n", 1);
	if (!stack_from || !(*stack_from))
		return ;
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

// t_list	*ft_push(t_list *list_push, t_list *list_recieve)
// {
// 	if (!list_push && !list_recieve)
// 		return (NULL);
// 	if (!list_push)
// 		return (list_recieve);
// 	else if (!list_recieve)
// 		list_push->next = NULL;
// 	else
// 		list_push->next = list_recieve;
// 	list_recieve = list_push;
// 	return (list_recieve);
// }
