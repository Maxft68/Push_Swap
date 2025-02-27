/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:31:14 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/27 20:41:08 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int cost_index(t_list **head, int nb)
{
	int i;
	int size;
	t_list *current;
	
	if (!head || !(*head))
		return (-1);
	i = 0;
	size = ft_lstsize(*head);
	current = *head;
	while (i < size)
	{
		if (current->index == nb)
			break;
		current = current->next;
		i++;
	}
	if (i == size)
		return (-1); // rien trouver
	if (i > (size / 2))
		return (0); // reverse rotate better
	return (1);     // rotate better
}

int cost_moves(t_list **head, int target)
{
	int i;
	int size;
	t_list *current;

	if (!head || !(*head))
		return (-1);
	i = 0;
	size = ft_lstsize(*head);
	current = *head;
	while (i < size)
	{
		if (current->index == target)
			break;
		current = current->next;
		i++;
	}
	if (i == size)
		return (-1);
	if (i <= (size / 2))
		return (i); 
	else
		return (size - i);
}

int cost_block(t_list **head, int nb)
{
	int i;
	t_list *current;
	t_list *start;

	if (!head || !(*head))
		return (-1);  // Liste vide ou invalide

	current = *head;
	start = *head;
	i = 0;
	while (1)
	{
		if (current->block == nb)
			break;
		if (current->next == start)
			break;
		current = current->next;
		i++;
	}
	// Si on a fait un tour complet sans trouver le block nb, on retourne -1
	if (current->block != nb)
		return (-1);

	if (i > (ft_lstsize(*head) / 2))
		return (0); // 0 = reverse rotate better
	return (1);
}
