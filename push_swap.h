/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:05:07 by filferna          #+#    #+#             */
/*   Updated: 2024/08/05 14:10:15 by filferna         ###   ########.fr       */
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

typedef struct node
{
	long			number;
	int				index;
	struct node	*next;
}	node;
void	ft_newlist(char **arguments, node **stack_a);
void	*free_all_list(node **stack);
void	ft_reverse_rotate(char x, node **stack_a, node **stack_b);
void	ft_push(char x, node **stack_from, node **stack_to);
void	ft_sort(node **stack_a, node **stack_b);
void	ft_swap(char x, node **list_a, node **list_b);
void	ft_rotate(char x, node **stack_a, node **stack_b);
int		ft_sorted(node **stack_a);
int 	size_of_list(node **stack);
int		ft_max_bits(node **stack);
void	ft_sort_index(node **stack, unsigned int index);
void	ft_index(node **stack_a);
int		ft_atol(const char *str);
int		verify(char **args);
int		int_size(node **stack);
void	sort_3(node **stack_a, node **stack_b);
int		get_min(node **stack);
void	small(node **stack_a, node **stack_b);
void	sort_2(node **stack_a, node **stack_b);
void	sort_3(node **stack_a, node **stack_b);
void	sort_4(node **stack_a, node **stack_b);
void	sort_5(node **stack_a, node **stack_b);
void	ft_clean_matrix(char **matrix);


#endif
