/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:31:14 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/21 20:44:29 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int cost(t_list **head, int index)
{
	int i = 0;
	t_list *current;
	
	current = *head;
	while (current->next->index != index)
	{
		current = current->next;
		i++;
	}
	//printf(" LE COUT EST DE %d\n", i);
	if (i + 1 > (ft_lstsize(*head) / 2))
		return(0); // 0 = reverse rotate better
	return(1);
}
