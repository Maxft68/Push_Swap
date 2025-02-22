/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:33:15 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/22 01:44:38 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo_three(t_list **head)
{
	//printf("ALGO THREE TU PUES");
	t_list *a;
	t_list *n;
	
	a = *head;
	n = (*head)->next;
	if (a->index < n->index)
	{
		printf("rra\n");
		reverse_rotate_a(head);
		a = *head;
		n = (*head)->next;
	}
	else if (a->index > n->index && a->index > n->next->index)
	{
		printf("ra\n");
		rotate_a(head);
		a = *head;
		n = (*head)->next;
	}	
	if ((*head)->index > (*head)->next->index)
	{
		printf("sa\n");
		swap_a(head);
	}
}

// void algo_three(t_list **head)
// {
// 	int a, b, c;
// 	if (ft_lstsize(*head) != 3)
// 		return;
// 	a = (*head)->index;
// 	b = (*head)->next->index;
// 	c = (*head)->next->next->index;
// 	if (a < b && b < c)
// 		return;
// 	if (a > b && a < c)
// 		swap_a(head);
// 	else if (a > b && b > c)
// 	{
// 		swap_a(head);
// 		reverse_rotate_a(head);
// 	}
// 	else if (a > c && c > b)
// 		rotate_a(head);
// 	else if (a < b && a > c)
// 		reverse_rotate_a(head);
// 	else if (a < b && c < b && a < c)
// 	{
// 		swap_a(head);
// 		rotate_a(head);
// 	}
// }
