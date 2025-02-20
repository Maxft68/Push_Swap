/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:33:15 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/20 22:51:15 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo_three(t_list **head)
{
	t_list *a;
	t_list *n;
	
	a = *head;
	n = (*head)->next;
	if (a->index < n->index)
	{
		printf("rra\n");
		reverse_rotate_a(head);
	}
	else if (a->index > n->index && a->index > n->next->index)
	{
		printf("ra\n");
		rotate_a(head);
	}	
	if ((*head)->index > (*head)->next->index)
	{
		printf("sa\n");
		swap_a(head);
	}		
}
