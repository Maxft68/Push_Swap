/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:02:38 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/21 22:11:32 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_index(t_list **head)
{
	t_list *current;
	t_list *compare;

	current = *head;
	while (1)
	{
		current->index = 1;
		compare = *head;
		while (1)
		{
			if (current->value > compare->value)
			{
				current->index++;
			}
			compare = compare->next;
			if (compare == *head)
				break;
		}
		current = current->next;
		if (current == *head)
			break;
	}	
}

t_list *index_min(t_list **head)
{
	t_list *current;
	t_list *index_min;
	
	if (!head || !*head)
		return NULL;
	current = (*head)->next;
	index_min = *head;
	while(current->next != *head)
	{
		if (current->index < index_min->index)
			index_min = current;
		current = current->next;
	}
	if (current->index < index_min->index)
		index_min = current;
	return(index_min);
}

