/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:31:14 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/28 15:41:11 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*******************************************************************************
The best way to move a node to the top 1 =rotate 0 =reverse_rotate -1 =not found
*******************************************************************************/

int	cost_index(t_list **head, int nb)
{
	int		i;
	int		size;
	t_list	*current;

	if (!head || !(*head))
		return (-1);
	i = 0;
	size = ft_lstsize(*head);
	current = *head;
	while (i < size)
	{
		if (current->index == nb)
			break ;
		current = current->next;
		i++;
	}
	if (i == size)
		return (-1);
	if (i > (size / 2))
		return (0);
	return (1);
}
/*******************************************************************************
Cost how many moves needed to move the node on the top (with the shortest path)
*******************************************************************************/

int	cost_moves(t_list **head, int target)
{
	int		i;
	int		size;
	t_list	*current;

	if (!head || !(*head))
		return (-1);
	i = 0;
	size = ft_lstsize(*head);
	current = *head;
	while (i < size)
	{
		if (current->index == target)
			break ;
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

/*******************************************************************************
Find the best way to move any number from a block(chunk) to the top
1 for rotate / 0 for reverse rotate / -1 if no more number from this block
*******************************************************************************/

int	cost_block(t_list **head, int nb)
{
	int		i;
	t_list	*current;
	t_list	*start;

	if (!head || !(*head))
		return (-1);
	current = *head;
	start = *head;
	i = 0;
	while (1)
	{
		if (current->block == nb)
			break ;
		if (current->next == start)
			break ;
		current = current->next;
		i++;
	}
	if (current->block != nb)
		return (-1);
	if (i > (ft_lstsize(*head) / 2))
		return (0);
	return (1);
}
