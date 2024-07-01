/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:05:07 by filferna          #+#    #+#             */
/*   Updated: 2024/06/29 20:59:16 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct n_list
{
	int				number;
	struct n_list	*next;
}	t_list;

t_list	*ft_newlist(char **arguments);
int		ft_atoi(char *str);
void	*free_all_list(t_list *list);
// t_list	*ft_push(t_list *list_push, t_list *list_recive);
void	ft_push(t_list **stack_from, t_list **stack_to);
void	ft_sort(t_list list_a, t_list list_b);
void	ft_swap(char x, t_list *list_a, t_list *list_b);

#endif