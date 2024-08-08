/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:37:34 by filferna          #+#    #+#             */
/*   Updated: 2024/04/25 21:34:11 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	int i = 2;
// 	t_list *root = ft_lstnew(av[1]);
// 	while (av[i])
// 	{
// 		root->next = ft_lstnew(av[i]);
// 		i++;
// 	}
// 	t_list *last = ft_lstlast(root);
// 	printf("%s\n", (char *)last->content);
// 	return (0);
// }