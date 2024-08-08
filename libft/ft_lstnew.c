/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:52:39 by filferna          #+#    #+#             */
/*   Updated: 2024/04/25 17:34:38 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lista;

	lista = (t_list *)(malloc)(sizeof(t_list));
	if (!lista)
		return (NULL);
	lista->content = content;
	lista->next = NULL;
	return (lista);
}

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	char *str = av[1];
// 	t_list *lista = ft_lstnew(str);
// 	printf("%s", (char *)lista->content);
// 	free(lista);
// 	return (0);
// }