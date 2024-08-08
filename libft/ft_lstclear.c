/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:31:28 by filferna          #+#    #+#             */
/*   Updated: 2024/04/27 19:11:13 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void delete(void * str)
// {
// 	free((char *)str);
// 	return ;
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (lst && *lst)
	{
		temp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	return ;
}

// int main(void)
// {
// 	char *str = "sure";
// 	char *str1 = "wtv";
// 	char *str2 = "no";
// 	char *str3 = ":(";
// 	t_list *elem = ft_lstnew(str);
// 	t_list *elem1 = ft_lstnew(str1);
// 	t_list *elem2 = ft_lstnew(str2);
// 	t_list *elem3 = ft_lstnew(str3);
// 	elem->next = elem1;
// 	elem->next = elem2;
// 	elem->next = elem3;
// 	ft_lstclear(&elem2, delete);
// 	while (elem)
// 	{
// 		printf("%s\n", (char *)elem->content);
// 		elem = elem->next;
// 	}
// 	return (0);
// }