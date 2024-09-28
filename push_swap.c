/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:04:36 by filferna          #+#    #+#             */
/*   Updated: 2024/09/28 12:02:45 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_of_list(t_node **stack)
{
	int		result;
	t_node	*temp;

	if (!*stack)
		return (0);
	result = 0;
	temp = *stack;
	while (temp->next)
	{
		result += 1;
		temp = temp->next;
	}
	return (result);
}

int	ft_sorted(t_node **stack_a)
{
	t_node	*temp;

	temp = *stack_a;
	while (temp->next)
	{
		if (temp->number > temp->next->number)
			return (0);
		else
			temp = temp->next;
	}
	return (1);
}

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	int		max_bits;
	int		bits;
	int		stack_size;
	int		j;
	t_node	*temp;

	bits = -1;
	j = 0;
	stack_size = size_of_list(stack_a);
	ft_index(stack_a);
	max_bits = ft_max_bits(stack_a);
	while (!ft_sorted(stack_a) && ++bits < max_bits)
	{
		j = 0;
		while (j++ <= stack_size)
		{
			temp = *stack_a;
			if (((temp->index >> bits) & 1) == 1)
				ft_rotate('a', stack_a, stack_b);
			else
				ft_push('b', stack_a, stack_b);
		}
		while (*stack_b)
			ft_push('a', stack_b, stack_a);
	}
}

int	verify(char **args)
{
	int	i;
	int	j;

	j = -1;
	while (args[++j])
	{
		i = 0;
		while (args[j][i])
		{
			if ((args[j][i] == '-' || args[j][i] == '+') && i == 0)
				i++;
			if (args[j][i] == 0 || !ft_isdigit(args[j][i]))
				return (ft_printf("ERROR\n"));
			if (i > 11)
				return (ft_printf("ERROR\n"));
			i++;
		}
	}
	if (j < 2)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_node	**stack_a;
	t_node	**stack_b;
	char	**args;

	if (ac < 2)
		return (0);
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = ++av;
	if (verify(args))
		return (ft_clean_matrix(args, ac));
	stack_a = (t_node **)malloc(sizeof(t_node));
	stack_b = (t_node **)malloc(sizeof(t_node));
	*stack_b = NULL;
	ft_newlist(args, stack_a);
	if (ac == 2)
		ft_clean_matrix(args, ac);
	if (size_of_list(stack_a) >= 5 && !int_size(stack_a))
		ft_sort(stack_a, stack_b);
	else if (!int_size(stack_a) && size_of_list(stack_a) < 5)
		small(stack_a, stack_b);
	free_all_list(stack_a);
	free_all_list(stack_b);
	return (0);
}
