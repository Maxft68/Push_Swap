/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:44:29 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/20 13:47:29 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate_a(t_list **stack)
{
	if (!*stack || !stack)
		return;
	*stack = (*stack)->prev;
}

void reverse_rotate_b(t_list **stack)
{
	if (!*stack || !stack)
		return;
}

void double_reverse_rotate(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !stack_a || !*stack_b || !stack_b)
		return;
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}