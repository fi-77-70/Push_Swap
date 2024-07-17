/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:04:36 by filferna          #+#    #+#             */
/*   Updated: 2024/07/17 20:32:20 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int size_of_list(t_list **stack)
{
	int result;
	t_list *temp;

	result = 0;
	temp = *stack;
	while (temp->next)
	{
		result += 1;
		temp = temp->next; 
	}
	return (result);
}
int	ft_sorted(t_list **stack_a)
{
	int		min;
	int		size;
	t_list	*temp;
	t_list	*begin;

	if (!*stack_a)
		return (0);
	temp = *stack_a;
	min = 2147483647;
	while(temp)
	{
		if (temp->number < min)
			min = temp->number;
		temp = temp->next;
	}
	temp = *stack_a;
	while (temp->number != min)
		temp = temp->next;
	begin = temp;
	size = size_of_list(stack_a);
	while (--size)
	{
		if (!begin->next)
		{
			if (begin->number > (*stack_a)->number)
				return (0);
			begin = *stack_a;
			continue ;
		}
		if (begin->number > begin->next->number)
			return (0);
		begin = begin->next;
	}
	// printf("ORDENADOOOOOOOOOO");
	return (1);
}

void	ft_handle_b(t_list **stack_a, t_list **stack_b, int *module, int *number_of_moves)
{
	int 	max;
	int		min;
	t_list	*temp;

	temp = *stack_b;
	while (*stack_b)
	{
		min = get_maximum_digit(stack_b, module);
		max = get_maximum_digit(stack_b, module);
		// printf ("min ------> [%d]\n", min);
		// printf ("conta ----> [%d]\n", ((*stack_b)->number % *module));
		// printf("stack_b ---> [%d]\n", (*stack_b)->number);
		// printf("module ----> [%d]\n", *module);
		if(((*stack_b)->number % *module) == max)
		{
			ft_push('a', stack_b, stack_a);
			*number_of_moves += 1;
		}
		else if((((*stack_b)->number % *module) == min) && *stack_b)
		{
			ft_push('a', stack_a, stack_b);
			ft_rotate('a', stack_a, stack_b);
			*number_of_moves += 1;
		}
		else
		{
			ft_rotate('b', stack_a, stack_b);
			*number_of_moves += 1;
		}
	}
	*module = *module * 10;
	return ;
}

int	get_maximum_digit(t_list **stack, int *module)
{
	t_list	*temp;
	int		minimum;

	minimum = 0;
	temp = *stack;
	while (temp)
	{
		if((temp->number % *module) > minimum)
			minimum = temp->number % *module;
		temp = temp->next;
	}
	return (minimum);
}

int	get_minimum_digit(t_list **stack, int *module)
{
	t_list	*temp;
	int		minimum;

	minimum = 2147483647;
	temp = *stack;
	while (temp)
	{
		if((temp->number % *module) < minimum)
			minimum = temp->number % *module;
		temp = temp->next;
	}
	return (minimum);
}

void	ft_sort(t_list **stack_a, t_list **stack_b, int *module, int *number_of_moves)
{
	int	min;
	t_list	*temp;
	int		max;

	if (!*stack_a)
	{
		*module = *module *10;
		ft_handle_b(stack_a, stack_b, module, number_of_moves);
	}
	temp = *stack_a;
	while(temp)
	{
		// printf("stack_a------>[%d]", temp->number);
		temp = temp->next;
	}
	if (ft_sorted(stack_a))
		return ;
	while (*stack_a)
	{
		min = get_minimum_digit(stack_a, module);
		max =get_maximum_digit(stack_a, module);
		if((((*stack_a)->number % *module) == min) && *stack_a)
		{
			ft_push('b', stack_a, stack_b);
			*number_of_moves += 1;
		}
		else if((((*stack_a)->number % *module) == max) && *stack_a)
		{
			ft_push('b', stack_a, stack_b);
			ft_rotate('b', stack_a, stack_b);
			*number_of_moves += 1;
		}
		else
		{
			ft_rotate('a', stack_a, stack_b);
			*number_of_moves += 1;
		}
	}
	if(!ft_sorted(stack_a) || *stack_b)
		ft_sort(stack_a, stack_b, module, number_of_moves);
	return ;
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	// t_list	*temp;
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
	ft_sort(stack_a, stack_b, &module, &number_of_moves);
	// temp = *stack_a;
	// while (temp)
	// {
	// 	printf("%d\n", temp->number);
	// 	temp = temp->next;
	// }
	// printf("\nNumber of moves --> [%d]\n", number_of_moves);
	free_all_list(stack_a);
	free_all_list(stack_b);
	return (0);
}
