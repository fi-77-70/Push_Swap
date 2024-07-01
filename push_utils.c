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

void	*free_all_list(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return (NULL);
}

t_list	*ft_newlist(char **arguments)
{
	int		i;
	t_list	*f_list;
	t_list	*list;

	i = 1;
	f_list = (t_list *)malloc(sizeof(t_list));
	if (!f_list)
		return (NULL);
	f_list->number = ft_atoi(arguments[i++]);
	f_list->next = NULL;
	list = f_list;
	while (arguments[i])
	{
		list->next = (t_list *)malloc(sizeof(t_list));
		if (!list->next)
			return (free_all_list(f_list));
		list = list->next;
		list->number = ft_atoi(arguments[i]);
		list->next = NULL;
		i++;
	}
	return (f_list);
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
