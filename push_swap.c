/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:04:36 by filferna          #+#    #+#             */
/*   Updated: 2024/07/16 19:33:28 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list **stack_a, t_list **stack_b, int *module)
{
	t_list	*temp;
	int		number_1;
	int		number_2;

	temp = *stack_a;
	if (*stack_b)
		if ((*stack_b)->number)
			return (0);
	while (temp->next)
	{
		number_1 = temp->number;
		number_2 = temp->next->number;
		if (number_1 >= *module)
			number_1 = number_1 % *module;
		else
			number_1 = 0;
		if (number_2 >= *module)
			number_2 = number_2 % *module;
		else
			number_2 = 0;
		if (number_1 > number_2)
			*module = *module;
		else
			*module = *module * 10;
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_sort(t_list **stack_a, t_list **stack_b, int *module, int *number_of_moves)
{
	int	number_1;
	int number_2;

	number_1 = (*stack_a)->number;
	number_2 = (*stack_a)->next->number;
	if (number_1 >= *module)
		number_1 = number_1 % *module;
	else if (*module > 10)
		number_1 = 0;
	if (number_2 >= *module)
		number_2 = number_2 % *module;
	else if (*module > 10)
		number_1 = 0;
	if (number_1 > number_2)
	{
		ft_swap('a', stack_a, stack_b);
		ft_rotate('a', stack_a, stack_b);
		*number_of_moves = *number_of_moves + 2;
	}
	if (number_1 <= number_2)
	{
		ft_rotate('a', stack_a, stack_b);
		*number_of_moves = *number_of_moves + 1;
	}
	return ;
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*temp;
	int		module;
	int		number_of_moves;

	number_of_moves = 0;
	module = 10;
	if (ac <= 2)
	{
		printf("Please Input a list of numbers to sort -----> ex:(-345, 0, 42, 5042, 3)");
		return (0);
	}
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_b = NULL;
	ft_newlist(av, stack_a);
	if (!(*stack_a))
		return (printf("Stack_A não foi criado\n"));
	while (!sorted(stack_a, stack_b, &module))
		ft_sort(stack_a, stack_b, &module, &number_of_moves);
	temp = *stack_a;
	while (temp)
	{
		printf("%d\n", temp->number);
		temp = temp->next;
	}
	printf("\nNumber of moves --> [%d]\n", number_of_moves);
	free_all_list(stack_a);
	free_all_list(stack_b);
	return (0);
}
