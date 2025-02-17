/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:23:05 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/17 17:23:08 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_del_one(t_list **head)
{
	t_list *old_head;
	old_head = *head;
	t_list *prev;
	t_list *next;
	
	if(!*head || !head)
		return;
	next = (*head)->next;
	prev = (*head)->prev;
	if(*head == (*head)->next)
	{
		free(*head);
		*head = NULL;
		return;
	}
	else
	{
		next->prev = prev;
		prev->next = next;
		*head = next;
	}
	free(old_head);
	old_head = NULL;
}
void ft_lstclear(t_list **lst)
{
	t_list *temp;
	t_list *head;
	
	if (lst == NULL)
		return;
	head = *lst;
	while (*lst && (*lst)->next != head)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	if (*lst)
	{
		free(*lst);
	}
	*lst = NULL;
}