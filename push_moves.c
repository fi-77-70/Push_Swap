/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:22:09 by filferna          #+#    #+#             */
/*   Updated: 2024/06/29 21:26:52 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(char x, t_list *list_a, t_list *list_b)
{
	int	temp;

	if (x == 's' && list_a->next->number && list_b->next->number)
	{
		ft_swap('a', list_a, list_b);
		ft_swap('b', list_a, list_b);
		return ;
	}
	else if (x == 'a' && list_a->next->number)
	{
		temp = list_a->number;
		list_a->number = list_a->next->number;
		list_a = list_a->next;
		list_a->number = temp;
	}
	else if(x == 'b' && list_b->next->number)
	{
		temp = list_b->number;
		list_b->number = list_b->next->number;
		list_b = list_b->next;
		list_b->number = temp;
	}
	return ;
}

void	ft_push(t_list **stack_from, t_list **stack_to)
{
	t_list	*list_push;
	t_list	*list_receive;
	t_list	*temp;

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
