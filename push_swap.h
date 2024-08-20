/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:05:07 by filferna          #+#    #+#             */
/*   Updated: 2024/08/19 14:08:13 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct t_node
{
	long			number;
	int				index;
	struct t_node	*next;
}	t_node;
void	ft_newlist(char **arguments, t_node **stack_a);
void	*free_all_list(t_node **stack);
void	ft_reverse_rotate(char x, t_node **stack_a, t_node **stack_b);
void	ft_push(char x, t_node **stack_from, t_node **stack_to);
void	ft_sort(t_node **stack_a, t_node **stack_b);
void	ft_swap(char x, t_node **list_a, t_node **list_b);
void	ft_rotate(char x, t_node **stack_a, t_node **stack_b);
int		ft_sorted(t_node **stack_a);
int		size_of_list(t_node **stack);
int		ft_max_bits(t_node **stack);
void	ft_sort_index(t_node **stack, unsigned int index);
void	ft_index(t_node **stack_a);
long	ft_atol(const char *str);
int		verify(char **args);
int		int_size(t_node **stack);
void	sort_3(t_node **stack_a, t_node **stack_b);
int		get_min(t_node **stack);
void	small(t_node **stack_a, t_node **stack_b);
void	sort_2(t_node **stack_a, t_node **stack_b);
void	sort_3(t_node **stack_a, t_node **stack_b);
void	sort_4(t_node **stack_a, t_node **stack_b);
void	sort_5(t_node **stack_a, t_node **stack_b);
int		ft_clean_matrix(char **matrix, int ac);

#endif
