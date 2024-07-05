/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:04:36 by filferna          #+#    #+#             */
/*   Updated: 2024/06/29 21:37:01 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*temp;

	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));	
	if(ac <= 2)
	{
		printf("Please Input a list of numbers to sort -----> ex:(-345, 0, 42, 5042, 3)");
		return (0);
	}
	*stack_b = NULL;
	ft_newlist(av, stack_a);
	if (!(*stack_a))
		return (printf("Stack_A não foi criado\n"));
	ft_swap('a', stack_a, stack_b);
	ft_push(stack_a, stack_b);
	ft_rotate('a', stack_a, stack_b);
	temp = *stack_a;
	while(temp)
	{
		printf("Stack_A [%d]\n", temp->number);
		temp = temp->next;
	}
	temp = *stack_b;
	while(temp)
	{
		printf("Stack_B [%d]\n", temp->number);
		temp = temp->next;
	}
	free_all_list(stack_a);
	free_all_list(stack_b);
	return (0);
}
