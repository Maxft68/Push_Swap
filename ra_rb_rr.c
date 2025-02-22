/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:21:07 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/22 00:39:17 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_list **stack)
{
	if (!*stack || !stack)
		return;
	*stack = (*stack)->next;
}

void rotate_b(t_list **stack)
{
	if (!*stack || !stack)
		return;
	*stack = (*stack)->next;
}

void double_rotate(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !stack_a || !*stack_b || !stack_b)
		return;
	rotate_a(stack_a);
	rotate_b(stack_b);
}