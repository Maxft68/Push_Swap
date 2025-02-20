/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:02:38 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/20 20:59:51 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_index(t_list **head)
{
	t_list *current;
	t_list *compare;

	current = *head;
	while (current)
	{
		current->index = 1;
		compare = *head;
		while (compare)
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

