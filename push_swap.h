/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:22:31 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/28 19:01:58 by mdsiurds         ###   ########.fr       */
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
	int				block;
	int				mid_block;
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
void	swap_a(t_list **stack, int print_sa);
void	swap_b(t_list **stack, int print_sb);
void	swap_a_b(t_list **stack_a, t_list **stack_b, int print_ss);
void	push_a(t_list **from_b, t_list **to_a, int print_pa);
void	push_b(t_list **from_a, t_list **to_b, int print_pb);
void	rotate_a(t_list **stack, int print_ra);
void	rotate_b(t_list **stack, int print_rb);
void	double_rotate(t_list **stack_a, t_list **stack_b, int print_rr);
void	reverse_rotate_a(t_list **stack, int print_rra);
void	reverse_rotate_b(t_list **stack, int print_rrb);
void	dual_reverse_rotate(t_list **stack_a, t_list **stack_b, int print_rrr);
int		control(t_list *head);
void	algo_three(t_list **head);
void	ft_index(t_list **head);
void	algo_five(t_list **head, t_list **head2);
void	free_argv(char **argv);
t_list	*index_min(t_list **head);
void	big_algo(t_list **head, t_list **head2, int block_size);
int		create_block(t_list **head, float nb_blocks);
int		cost_index(t_list **head, int nb);
int		cost_block(t_list **head, int nb);
int		cost_moves(t_list **head, int target);
void	big_algo_back_to_head(t_list **head, t_list **head2);
void	inter_function_big_algo(t_list **head, t_list **head2, int *s);
void	clear_all_all(t_list **head, t_list **head2, char **argvsplit);


#endif