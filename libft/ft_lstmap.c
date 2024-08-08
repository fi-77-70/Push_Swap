/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:31:44 by filferna          #+#    #+#             */
/*   Updated: 2024/04/29 21:14:01 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
void	del(void *content)
{
	free(content);
}

void	*f(void *content)
{
	return (content);
}
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = ft_lstnew((*f)(lst->content));
	if (!new_lst)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (new_node == NULL)
		{
			(*del)(new_node->content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/* int	main(int ac, char **av)
{
	(void)ac;
	int i = 1;
	t_list  *lst = ft_lstnew(av[i]);
	t_list *node;
	while(av[++i])
	{
	node = ft_lstnew(av[i]);
	ft_lstadd_back(&lst, node);
	}
	t_list *new = ft_lstmap(lst, f, del);
	while (new)
	{
		printf("%s\n", (char *)new->content);
		new = new->next;
	}
	ft_lstclear(&lst, del);
	free(lst);
	return (0);
} */
