/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:22:31 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/21 14:43:26 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void	ft_lstclear(t_list **lst);
void	ft_del_one(t_list **head);
int		ft_lstsize(t_list *list);
t_list	*ft_lstnew(char *the_value);
t_list	*ft_lstadd_back(t_list *lst, t_list *new);
t_list	*ft_lstadd_front(t_list **lst, t_list *new);
void	print_list(t_list *head); // inutile a rendre ??
void	swap_a(t_list **stack);
void	swap_b(t_list **stack);
void	swap_a_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **from_b, t_list **to_a);
void	push_b(t_list **from_b, t_list **to_a);
void	rotate_a(t_list **stack);
void	rotate_b(t_list **stack);
void	double_rotate(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack);
void	reverse_rotate_b(t_list **stack);
void	double_reverse_rotate(t_list **stack_a, t_list **stack_b);
int		control(t_list *head);
void	algo_three(t_list **head);
void	ft_index(t_list **head);
void	algo_five(t_list **head, t_list **head2);
void	free_argv(char **argv);
t_list	*index_min(t_list **head);


#endif