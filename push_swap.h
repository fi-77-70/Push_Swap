/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:05:07 by filferna          #+#    #+#             */
/*   Updated: 2024/07/17 17:25:35 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct t_list
{
	int				number;
	struct t_list	*next;
}	t_list;
void	ft_newlist(char **arguments, t_list **stack_a);
int		ft_atoi(char *str);
void	*free_all_list(t_list **stack);
void	ft_reverse_rotate(char x, t_list **stack_a, t_list **stack_b);
void	ft_push(char x, t_list **stack_from, t_list **stack_to);
void	ft_sort(t_list **stack_a, t_list **stack_b, int *module, int *number_of_moves);
void	ft_swap(char x, t_list **list_a, t_list **list_b);
void	ft_rotate(char x, t_list **stack_a, t_list **stack_b);
int		get_minimun_digit(t_list **stack, int *module);
void	ft_handle_b(t_list **stack_a, t_list **stack_b, int *module, int *number_of_moves);
int		ft_sorted(t_list **stack_a);
int	get_maximum_digit(t_list **stack, int *module);

#endif
