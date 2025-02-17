/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:23:17 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/17 18:35:59 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	t_list *temp;
	t_list *next;
	t_list *prev;
	
	prev = (*stack_a)->prev;
	next = (*stack_a)->next;
	temp = *stack_a;
	
	if (!*stack_a || !stack_a || !(*stack_a)->next)
		return;
	else if ((*stack_a)->next == (*stack_a)->prev) //2ELEMENTS
	{
		temp = *stack_a;
		*stack_a = next;
		next = temp;
	}
	
}