/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:33:15 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/28 15:28:10 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_three(t_list **head)
{
	t_list	*a;
	t_list	*n;

	a = *head;
	n = (*head)->next;
	if (a->index < n->index)
	{
		reverse_rotate_a(head, 1);
		a = *head;
		n = (*head)->next;
	}
	else if (a->index > n->index && a->index > n->next->index)
	{
		rotate_a(head, 1);
		a = *head;
		n = (*head)->next;
	}
	if ((*head)->index > (*head)->next->index)
		swap_a(head, 1);
}
