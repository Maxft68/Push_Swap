/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:44:54 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/21 14:41:52 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *index_min(t_list **head)
{
	t_list *current;
	t_list *index_min;
	
	current = (*head)->next;
	index_min = *head;
	while(current != *head)
	{
		if (current->index > index_min->index)
			current = current->next;
		index_min = current;
	}
	return(index_min);
}

void algo_five(t_list **head, t_list **head2)
{
	t_list *a;
	t_list *n;
	
	a = *head;
	n = (*head)->next;
	if (a->index)
	{
		// printf("sa\n");
		// swap_a(head);
		printf("pb\n");
		push_b(head, head2);
		printf("pb\n");
		push_b(head, head2);
		// print_list(*head);
		if (!control(*head))
			algo_three(head);
		printf("rr\n");	
		double_rotate(head, head2);
		printf("pa\n");
		push_a(head2, head);
		printf("rra\n");
		reverse_rotate_a(head);
		printf("pa\n");
		push_a(head2, head);
		if (!control(*head))
			swap_a(head);
		
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
	}
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
