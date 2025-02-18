/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:22:31 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/18 19:19:56 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
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

#endif