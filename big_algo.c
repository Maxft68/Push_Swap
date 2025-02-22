/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:16:01 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/22 01:45:44 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	block_size(int size_head)
// {
// 	int 
// }

void	create_block(t_list **head)
{
	t_list *cur;
	int size;
	int size_block;
	
	cur = *head;
	size = ft_lstsize(*head);
	size_block = size / 5; //pour 100nb pour commencer
	while (1)
	{
		if (cur->index <= size_block)
			cur->block = 1;
		else if (cur->index <= (size_block * 2) && cur->index > (size_block))
			cur->block = 2;
		else if (cur->index <= (size_block * 3) && cur->index > (size_block * 2))
			cur->block = 3;
		else if (cur->index <= (size_block * 4) && cur->index > (size_block * 3))
			cur->block = 4;
		else
			cur->block = 5;
		cur = cur->next;
		if (cur == *head)
			break;
	}
}

void	big_algo(t_list **head, t_list **head2)
{
	t_list *cur;
	t_list *n;
	int i;
	
	cur = *head;
	n = (*head)->next;
	i = 1;
	
	while (ft_lstsize(*head) > 3)
	{
		if (cur->block == i)
		{
			printf("pb\n");
			push_b(head, head2);
		}
		else if (cost_block(head, i) == -1) //pas trouve
		{
			i++;
		}
		else if (cost_block(head, i) == 1)
		{
			printf("ra\n");
			rotate_a(head);
		}
		else
		{
			printf("rra\n");
			reverse_rotate_a(head);
		}
		cur = *head;
		
		printf("----HEAD big algo----\n");
		print_list(*head);
		printf("----HEAD2 big algo----\n");
		print_list(*head2);
	}
	if (ft_lstsize(*head) == 3 && control(*head) != 1)
		algo_three(head);
	printf("----HEAD apres big + 3----\n");
	print_list(*head);
}
