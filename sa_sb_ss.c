/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:23:17 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/22 01:43:00 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack)
{
	t_list *temp;
	t_list *second;
	t_list *last;
	t_list *third;
	
	temp = *stack;
	second = (*stack)->next;
	if (!*stack || !stack || !(*stack)->next)
		return;
	else if ((*stack)->next->next == *stack) //2ELEMENTS
		*stack = second;
	else
	{
		third = (*stack)->next->next;
		last = (*stack)->prev;
		temp->next = third; // SPECIFIQUE
		third->prev = temp; // SPECIFIQUE
		second->next = temp; //toujours pareil
		last->next = second; //toujours pareil
		second->prev = last; // always same
		temp->prev = second; // always
		*stack = second; //always
	}
	//ft_printf("sa");// ben non sinon double print quand ss.
}

void	swap_b(t_list **stack)
{
	t_list *temp;
	t_list *second;
	t_list *last;
	t_list *third;
	
	temp = *stack;
	second = (*stack)->next;
	if (!*stack || !stack || !(*stack)->next)
		return;
	else if ((*stack)->next->next == *stack) //2ELEMENTS
		*stack = second;
	else
	{
		third = (*stack)->next->next;
		last = (*stack)->prev;
		temp->next = third; // SPECIFIQUE
		third->prev = temp; // SPECIFIQUE
		second->next = temp; //toujours pareil
		last->next = second; //toujours pareil
		second->prev = last; // always same
		temp->prev = second; // always
		*stack = second; //always
	}
	//ft_printf("sa");// ben non sinon double print quand ss.
}

void	swap_a_b(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	//ft_printf("ss"); ??
}
