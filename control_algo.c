/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:14:26 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/28 15:56:46 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*******************************************************************************
Control if all the list is sorted in ascending
*******************************************************************************/

int	control(t_list *head)
{
	t_list	*temp;
	temp = head;
	
	while (temp->next != head)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
