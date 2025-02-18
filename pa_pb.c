/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:42:27 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/18 23:52:40 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list    *extract_node(t_list **from)
{
    t_list    *temp;

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
	// if (!to_a || !*to_a)
	// {
		
	// }
	t_list *new_a;
	printf("-------avantPUSH-------\n");
	print_list(*from_b);
	new_a = extract_node(from_b);
	//ft_lstadd_front(to_a, new_a);
	//ft_del_one(from_b);
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
	printf("-------apresPUSH_FROM-------\n");
	print_list(*from_b);
	printf("-------head2-------\n");
	print_list(*to_a);
}
