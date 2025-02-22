/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:31:14 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/22 00:17:42 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int cost_index(t_list **head, int nb)
{
	int i = 0;
	t_list *current;
	
	current = *head;
	while (current->next->index != nb)
	{
		current = current->next;
		i++;
	}
	//printf(" LE COUT EST DE %d\n", i);
	if (i + 1 > (ft_lstsize(*head) / 2))
		return(0); // 0 = reverse rotate better
	return(1);
}

// int cost_block(t_list **head, int nb)
// {
// 	int i = 0;
// 	t_list *current;
	
// 	current = *head;
// 	while (current->next->block != nb)
// 	{
// 		current = current->next;
// 		i++;
// 	}
// 	//printf(" LE COUT EST DE %d\n", i);
// 	if (i + 1 > (ft_lstsize(*head) / 2)) // A VERIFIER SI CEST 100%JUSTE ENCORE
// 		return(0); // 0 = reverse rotate better
// 	return(1);
// }
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
        if (current->next->block == nb)
            break;
        if (current->next == start)
            break;
        current = current->next;
        i++;
    }
    // Si on a fait un tour complet sans trouver le block nb, on retourne -1
    if (current->next->block != nb)
        return (-1);

    if (i + 1 > (ft_lstsize(*head) / 2))// A VERIFIER SI CEST 100%JUSTE ENCORE
        return (0); // 0 = reverse rotate better
    return (1);
}
