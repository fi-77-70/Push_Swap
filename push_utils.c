/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:12:40 by filferna          #+#    #+#             */
/*   Updated: 2024/06/29 19:36:13 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_all_list(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	if (stack)
		free (stack);
	return (NULL);
}

void	ft_newlist(char **arguments, t_list **stack_a)
{
	int	i;
	t_list	*list;

	i = 1;
	*stack_a = (t_list *)malloc(sizeof(t_list));
	if (!(*stack_a))
		return ;
	(*stack_a)->number = ft_atoi(arguments[i++]);
	(*stack_a)->next = NULL;
	list = *stack_a;
	while (arguments[i])
	{
		list->next = (t_list *)malloc(sizeof(t_list));
		if (!list->next)
		{
			free_all_list(stack_a);
			return ;
		}
		list = list->next;
		list->number = ft_atoi(arguments[i]);
		list->next = NULL;
		i++;
	}
	return ;
}

// t_list	*ft_list_b(int ac)
// {
// 	int		i;
// 	t_list	*f_list;
// 	t_list	*temp;

// 	if (!ac || ac == 0)
// 		return (NULL);
// 	i = ac;
// 	f_list = (t_list *)malloc(sizeof(t_list));
// 	if (!f_list)
// 		return (NULL);
// 	f_list->next = NULL;
// 	temp = f_list;
// 	while (--i)
// 	{
// 		temp->next = (t_list *)malloc(sizeof(t_list));
// 		if (!temp->next)
// 			return (free_all_list(f_list));
// 		temp = temp->next;
// 		temp->next = NULL;
// 	}
// 	return (f_list);
// }

int	ft_atoi(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	i = 0;
	sign = 1;
	while (!(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
