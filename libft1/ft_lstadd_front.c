/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 03:26:34 by filferna          #+#    #+#             */
/*   Updated: 2024/04/29 22:12:56 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **list, t_list *new_list)
{
	if (!list || !new_list)
		return ;
	new_list->next = *list;
	*list = new_list;
	return ;
}

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	char *str1 = av[1];
// 	char *str2 = av[2];
// 	t_list *original = ft_lstnew(str1);
// 	t_list *segunda = ft_lstnew(str2);
// 	ft_lstadd_front(&original, segunda);
// 	while(segunda)
// 	{
// 		printf("%s\n", (char *)segunda->content);
// 		segunda = segunda->next;
// 	}
// 	return (0);
// }
