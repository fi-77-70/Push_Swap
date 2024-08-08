/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 06:08:08 by filferna          #+#    #+#             */
/*   Updated: 2024/04/25 17:38:04 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new_list)
{
	t_list	*temp;

	if (!new_list)
		return ;
	if (!*list)
	{
		*list = new_list;
		return ;
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new_list;
	return ;
}

// int main(int argc, const char *argv[])
// {
// 	t_list		*begin;
// 	t_list		*elem;
// 	t_list		*elem2;
// 	t_list		*elem3;
// 	t_list		*elem4;
// 	char		*str = ft_strdup("lorem");
// 	char		*str2 = ft_strdup("ipsum");
// 	char		*str3 = ft_strdup("dolor");
// 	char		*str4 = ft_strdup("sit");

// 	elem = ft_lstnew(str);
// 	elem2 = ft_lstnew(str2);
// 	elem3 = ft_lstnew(str3);
// 	elem4 = ft_lstnew(str4);
// 	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
// 		return (0);
// 	else if (ft_atoi(argv[1]) == 1)
// 	{
// 		begin = NULL;
// 		ft_lstadd_back(&begin, elem);
// 		ft_lstadd_back(&begin, elem2);
// 		ft_lstadd_back(&begin, elem3);
// 		ft_lstadd_back(&begin, elem4);
// 		while (begin)
// 		{
// 			printf("%s\n", (char *)begin->content);
// 			begin = begin->next;
// 		}
// 	}
// 	return (0);
// }