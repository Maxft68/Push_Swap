/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:44:54 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/28 11:21:03 by mdsiurds         ###   ########.fr       */
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
			push_b(head, head2, 1);
			min = index_min(head);
		}
		else if (cost_index(head, min->index) == 1)
			rotate_a(head, 1);
		else
			reverse_rotate_a(head, 1);
		a = *head;
	}
	if (control(*head) != 1)
		algo_three(head);
	push_a(head2, head, 1);
	push_a(head2, head, 1);
}
