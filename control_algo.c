/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:14:26 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/21 22:36:47 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int control(t_list *head)
{
	//printf("CONTROL TU PUES\n");
	t_list *temp;
	temp = head;
	while(temp->next != head)
	{
		if (temp->value > temp->next->value)
			return(0);
		temp = temp->next;
	}
	return(1);
}