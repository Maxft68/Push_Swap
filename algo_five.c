/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:44:54 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/21 21:00:20 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo_five(t_list **head, t_list **head2)
{
	t_list *a;
	t_list *n;
	t_list *min;
	
	a = *head;
	n = (*head)->next;
	min = index_min(head);
	//printf("index du min = %d\n", min->index);
	// printf("-----head2-----\n");
	// 	print_list(*head2);
	while (ft_lstsize(*head) > 3)
	{
		if (a == min)
		{
			// printf("sa\n");
			// swap_a(head);
			printf("pb\n");
			push_b(head, head2);
			// printf("pb\n");
			// push_b(head, head2);
			// printf("-----head2-----\n");
			// print_list(*head2);
			// printf("-----head-----\n");
			// print_list(*head);
			min = index_min(head);
		}
		else if (cost(head, min->index) == 1)
		{
			printf("ra\n");
			rotate_a(head);
		}
		else
		{
			printf("rra\n");
			reverse_rotate_a(head);
		}
		a = *head;
		// ROTATE
	}
	if (!control(*head))
		algo_three(head);
	// printf("-----head apres algothree-----\n");
	// print_list(*head);	
	// push_a(head2, head);
	// printf("-----head apres 1push-----\n");
	// print_list(*head);
	// push_a(head2, head);
	// printf("-----head apres 2push-----\n");
	// print_list(*head);
	
		// printf("rr\n");	
		// double_rotate(head, head2);
	printf("pa\n");
	push_a(head2, head);
		// printf("rra\n");
		// reverse_rotate_a(head);
	printf("pa\n");
	push_a(head2, head);
		// if (!control(*head))
		// 	swap_a(head);
		
		//push_b(head2, head);
		// push_a(head2, head);
		// if (!control(*head))
		// algo_three(head);
		// push_a(head2, head);
		// if (!control(*head))
		// algo_three(head);
		// printf("pb\n");
		// push_b(head2, head);
		// printf("pb\n");
		// push_b(head2, head);
		// printf("sa\n");
		// swap_a(head);
	
	// else if (a->index > n->index && a->index > n->next->index)
	// {
	// 	printf("ra\n");
	// 	rotate_a(head);
	// }	
	// if ((*head)->index > (*head)->next->index)
	// {
	// 	printf("sa\n");
	// 	swap_a(head);
	// }
}
