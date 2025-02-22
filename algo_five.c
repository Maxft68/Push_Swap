/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:44:54 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/22 03:03:37 by mdsiurds         ###   ########.fr       */
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
	while (ft_lstsize(*head) > 3)
	{
		if (a == min)
		{
			printf("pb\n");
			push_b(head, head2);
			min = index_min(head);
		}
		else if (cost_index(head, min->index) == 1)
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
	}
	if (control(*head) != 1)
		algo_three(head);
	printf("pa\n");
	push_a(head2, head);
	printf("pa\n");
	push_a(head2, head);
}
