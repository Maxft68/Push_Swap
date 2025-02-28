/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:16:01 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/28 12:19:47 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*******************************************************************************
Create blocks - This function cuts the big list into small groups.
*******************************************************************************/
int create_block(t_list **head, float nb_blocks)
{
	t_list *cur;
	int size;
	int b_size;
	int i;
	
	cur = *head;
	i = 0;
	size = ft_lstsize(*head);
	b_size = (size - 3) / nb_blocks;
	cur = *head;
	while (i < 10)
	{
		while (1)
		{
			if (cur->index > size - 3)
				cur->block = 0;
			else if (cur->index <= b_size * (i + 1) && cur->index > b_size * i)
				cur->block = i + 1;
			cur = cur->next;
			if (cur == *head)
				break;
		}
		i++;
	}
	return(b_size);
}
/*******************************************************************************
Sorts number > 5 - Move to B
*******************************************************************************/
void	big_algo(t_list **head, t_list **head2, int block_size)
{
	t_list *cur;
	int i;
	
	cur = *head;
	i = 1;
	while (ft_lstsize(*head) > 3)
	{
		if (cur->block == i)
		{
			push_b(head, head2, 1);
			if (cur->index <= ((i - 1) * block_size) + 1 + (block_size / 2))
				rotate_b(head2, 1);
		}
		else if (cost_block(head, i) == -1)
			i++;
		else if (cost_block(head, i) == 1)
			rotate_a(head, 1);
		else
			reverse_rotate_a(head, 1);
		cur = *head;
	}
	if (ft_lstsize(*head) == 3 && control(*head) != 1)
		algo_three(head);
}

/*******************************************************************************
Sorts number > 5 - Move to A
*******************************************************************************/
void	big_algo_back_to_head(t_list **head, t_list **head2)
{
	t_list *cur;
	int s;
	
	s = ft_lstsize(*head2);
	while(ft_lstsize(*head2) != 0)
	{
		cur = *head2;
		if (cur->index == s)
		{
			push_a(head2, head, 1);
			s--;
		}
		else if (cur->index == (s - 1))
		{
			push_a(head2, head, 1);
			while((*head2)->index != s && ft_lstsize(*head2) > 0)
			{
				if (cost_index(head2, s) == 1)
					rotate_b(head2, 1);
				else if (cost_index(head2, s) == 0)
					reverse_rotate_b(head2, 1);
				else
					break;
			}
			push_a(head2, head, 1);
			swap_a(head, 1);
			s = s - 2;
		}
		else if (cost_moves(head, s) > cost_moves(head, (s - 1))) // si s-1 est plus rapidement trouver
		{
			if (cost_index(head2, (s - 1)) == 1)
				rotate_b(head2, 1);
			else
				reverse_rotate_b(head2, 1);
		}
		else if (cost_index(head2, s) == 1) // si s est plus rapidement trouver
			rotate_b(head2, 1);
		else
			reverse_rotate_b(head2, 1);
	}
}
