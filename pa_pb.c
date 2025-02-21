/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:42:27 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/21 00:29:43 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*extract_node(t_list **from)
{
	t_list *temp;

	if (!from || !(*from))
		return (NULL);
	temp = *from;
	if (!temp->next || !temp->prev || temp->next == temp)
		*from = NULL;
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		*from = temp->next;
	}
	return (temp);
}

void	push_a(t_list **from_b, t_list **to_a)
{
	if (!from_b || !*from_b)
		return;
	t_list *new_a;
	new_a = extract_node(from_b);
	if (!to_a || !(*to_a))
	{
		new_a->next = new_a;
		new_a->prev = new_a;
	}	
	else
	{
		new_a->next = *to_a;
		new_a->prev = (*to_a)->prev;
		(*to_a)->prev->next = new_a;
		(*to_a)->prev = new_a;
	}
	*to_a = new_a;
}
void	push_b(t_list **from_a, t_list **to_b)
{
	if (!from_a || !*from_a)
		return;
	t_list *new_a;
	new_a = extract_node(from_a);
	if (!to_b || !(*to_b))
	{
		new_a->next = new_a;
		new_a->prev = new_a;
	}	
	else
	{
		new_a->next = *to_b;
		new_a->prev = (*to_b)->prev;
		(*to_b)->prev->next = new_a;
		(*to_b)->prev = new_a;
	}
	*to_b = new_a;
}
