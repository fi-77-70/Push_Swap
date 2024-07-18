/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:04:36 by filferna          #+#    #+#             */
/*   Updated: 2024/07/18 21:41:48 by filferna         ###   ########.fr       */
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

static int logic_option(int min_moves, int max_moves)
{
	int	temp_min;
	int	temp_max;
	int final_choice;

	temp_min = min_moves;
	temp_max = max_moves;
	if (min_moves < 0)
		temp_min = min_moves * -1;
	if (max_moves < 0)
		temp_max = max_moves * -1;
	if (temp_min >= temp_max)
		final_choice = min_moves;
	else
		final_choice = max_moves;
	if (final_choice < 0)
		return (1);
	else
		return (2); 
}

static int best_option(t_list **stack_a, int *module,  int min, int max)
{
	t_list	*temp;
	int		min_moves;
	int		max_moves;

	if (!(*stack_a))
		return (0);
	if (size_of_list(stack_a) <= 1)
		return (0);
	min_moves = 0;
	max_moves = 0;
	temp = *stack_a;
	while (temp && (temp->number % *module) != min)
	{
		min_moves += 1;
		temp = temp->next;
	}
	temp = *stack_a;
	while (temp && (temp->number % *module) != max)
	{
		max_moves += 1;
		temp = temp->next;
	}
	min_moves = min_moves - (size_of_list(stack_a) / 2);
	max_moves = max_moves - (size_of_list(stack_a) / 2);
	return (logic_option(min_moves, max_moves));
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
	while (size--)
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
void	ft_handle_b(t_list **stack_a, t_list **stack_b, int *module, int *number_of_moves)
{
	int 	max;
	int		min;
	int		best;

	while (*stack_b)
	{
		min = get_maximum_digit(stack_b, module);
		max = get_maximum_digit(stack_b, module);
		best = best_option(stack_b, module, min, max);
		// printf ("min ------> [%d]\n", min);
		// printf ("conta ----> [%d]\n", ((*stack_b)->number % *module));
		// printf("stack_b ---> [%d]\n", (*stack_b)->number);
		// printf("module ----> [%d]\n", *module);
		if(((*stack_b)->number % *module) == max)
		{
			ft_push('a', stack_b, stack_a);
			*number_of_moves += 1;
		}
		else if((((*stack_b)->number % *module) == max) && *stack_b)
		{
			ft_push('a', stack_a, stack_b);
			ft_rotate('a', stack_a, stack_b);
			*number_of_moves += 1;
		}
		else
		{
			if (best == 1)
				ft_rotate('b', stack_a, stack_b);
			else
				ft_reverse_rotate('b', stack_a, stack_b);
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


/*
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
*/

void	ft_sort(t_list **stack_a, t_list **stack_b, int *module, int *number_of_moves)
{

	if (!*stack_a)
	{
		*module = *module *10;
		ft_handle_b(stack_a, stack_b, module, number_of_moves);
	}
	if (ft_sorted(stack_a))
		return ;
	
}

/*
void	ft_sort(t_list **stack_a, t_list **stack_b, int *module, int *number_of_moves)
{
	int	max;
	int	min;
	int	best;

	if (!*stack_a)
	{
		*module = *module *10;
		ft_handle_b(stack_a, stack_b, module, number_of_moves);
	}
	if (ft_sorted(stack_a))
		return ;
	while (*stack_a)
	{
		min = get_minimum_digit(stack_a, module);
		max = get_minimum_digit(stack_a, module);
		best = best_option(stack_a, module, min, max);
		if((((*stack_a)->number % *module) == min) && *stack_a)
		{
			ft_push('b', stack_a, stack_b);
			*number_of_moves += 1;
		}
		else if((((*stack_a)->number % *module) == min) && *stack_a)
		{
			ft_push('b', stack_a, stack_b);
			ft_rotate('b', stack_a, stack_b);
			*number_of_moves += 1;
		}
		else
		{
			if (best == 1)
				ft_rotate('a', stack_a, stack_b);
			else
				ft_reverse_rotate('a', stack_a, stack_b);
			*number_of_moves += 1;
		}
	}
	if(!ft_sorted(stack_a) || *stack_b)
		ft_sort(stack_a, stack_b, module, number_of_moves);
	return ;
}
*/

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
	// 	printf("stack_A --- > [%d]\n", temp->number);
	// 	printf("digits ---- > [%d]\n", temp->number_of_digits);
	// 	temp = temp->next;
	// }
	// temp = *stack_b;
	// 	while (temp)
	// {
	// 	printf("stack_a --- > [%d]\n", temp->number);
	// 	printf("digitsB---- > [%d]\n", temp->number_of_digits);
	// 	temp = temp->next;
	// }
	// printf("\nNumber of moves --> [%d]\n", number_of_moves);
	free_all_list(stack_a);
	free_all_list(stack_b);
	return (0);
}
