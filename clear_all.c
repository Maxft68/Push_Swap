/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:23:05 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/28 19:07:16 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_argv(char **argv)
{
	int    i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
}

void	ft_del_one(t_list **head)
{
	t_list	*old_head;
	t_list	*prev;
	t_list	*next;

	old_head = *head;
	if (!*head || !head)
		return ;
	next = (*head)->next;
	prev = (*head)->prev;
	if (*head == (*head)->next)
	{
		free(*head);
		*head = NULL;
		return ;
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

void	ft_lstclear(t_list **head)
{
	t_list	*current;
	t_list	*tmp;
	t_list	*a;

	if (!head || !(*head))
		return ;
	a = *head;
	while (a->next != *head)
		a = a->next;
	a->next = NULL;
	current = *head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*head = NULL;
}

void clear_all_all(t_list **head, t_list **head2, char **argvsplit)
{
	ft_lstclear(head);
	ft_lstclear(head2);
	if (argvsplit)
		free_argv(argvsplit);
	return;
}
