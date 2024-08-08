/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 06:31:06 by filferna          #+#    #+#             */
/*   Updated: 2024/04/25 17:34:57 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int main(void)
// {
// 	t_list *lst;

// 	lst = (t_list *)malloc(sizeof(t_list));
// 	lst->content = ft_strdup("hello ");
// 	lst->next = ft_lstnew(ft_strdup("world"));
// 	lst->next->next = ft_lstnew(ft_strdup(" mannn"));
// 	int i = ft_lstsize(lst);
// 	printf("%d\n", i);
// 	while (lst)
// 	{
// 		printf("%s", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	return (0);
// }