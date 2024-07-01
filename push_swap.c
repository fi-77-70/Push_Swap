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

	if(ac <= 2)
	{
		printf("Please Input a list of numbers to sort -----> ex:(-345, 0, 42, 5042, 3)");
		return (0);
	}
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	if (!stack_a)
		return (0);
	*stack_a = ft_newlist(av);
	ft_swap('a', *stack_a, *stack_b);
	ft_push(stack_a, stack_b);
	while(*stack_a)
	{
		printf("Stack_A [%d]\n", (*stack_a)->number);
		*stack_a = (*stack_a)->next;
	}
	while(*stack_b)
	{
		printf("Stack_B [%d]\n", (*stack_b)->number);
		*stack_b = (*stack_b)->next;
	}
	return (0);
}
