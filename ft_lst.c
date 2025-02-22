/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:41:30 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/21 22:37:14 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_lstsize(t_list *list)
{
	//printf("LSTSIZE TU PUES\n");
	t_list *temp;
	temp = list;
	int i;
	i = 1;
	if (list == NULL)
		return (0);
	while (temp->next != list)
	{
		i++;
		temp = temp->next;
	}	
	return (i);
}

t_list *ft_lstnew(char *the_value)
{
	t_list *new;
	
	new = malloc(sizeof(t_list));
	if (!new)
		return(NULL);
	new->value = atoi(the_value); // a remplacer par mon atoi
	new->index = 0;
	new->block = 0;
	new->next = NULL; // = (*new).next
	new->prev = NULL;
	return(new);
}

t_list *ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list *last;

	if (!lst)
	{
		new->next = new;
		new->prev = new;
		return new;
	}
	last = lst->prev;
	last->next = new;
	new->prev = last;
	new->next = lst;
	lst->prev = new;
	return lst;
}


t_list *ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst) //first add
	{
		new->next = new;
		new->prev = new;
		*lst = new;
		return(*lst);
	}
	if ((*lst)->next == *lst) // 2nd add
	{
		(*lst)->next = new;
		(*lst)->prev = new;
		new->next = *lst;
		new->prev = *lst;
		*lst = new;
		return(*lst);
	}
	t_list *last;
	last = (*lst)->prev;
	last->next = new;
	new->next = *lst;
	new->prev = last;
	(*lst)->prev = new;
	*lst = new;
	return(*lst);
}

void print_list(t_list *head)
{
	t_list *tmp;
	if (!head)
		return;
	tmp = head;
	while (1)
	{
		printf("contenu = %d; prev = %d; next = %d; index = %d; block = %d\n", tmp->value, tmp->prev->value, tmp->next->value, tmp->index, tmp->block);
		tmp = tmp->next;
		if (tmp == head)
			break;
	}
}

