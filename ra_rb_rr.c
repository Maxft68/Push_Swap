/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:21:07 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/28 15:45:05 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack, int print_ra)
{
	if (!*stack || !stack)
		return ;
	*stack = (*stack)->next;
	if (print_ra)
		printf("ra\n");
}

void	rotate_b(t_list **stack, int print_rb)
{
	if (!*stack || !stack)
		return ;
	*stack = (*stack)->next;
	if (print_rb)
		printf("rb\n");
}

void	double_rotate(t_list **stack_a, t_list **stack_b, int print_rr)
{
	if (!*stack_a || !stack_a || !*stack_b || !stack_b)
		return ;
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	if (print_rr)
		printf("rr\n");
}
