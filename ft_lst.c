/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:41:30 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/17 18:36:55 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_lstsize(t_list *list)
{
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
	new->next = NULL; // = (*new).next
	new->prev = NULL;
	return(new);
}

t_list *ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list *temp;
	
	if (!lst)
		return (new);
	temp = lst;
	if(temp->next == lst) //deuxieme node uniquement
	{
		temp->next = new;
		temp->prev = new;
		temp = lst->prev->next;
		temp = lst->next->prev;
		return(temp);
	}
	while(temp->next != lst && temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->prev = temp;
	new->next = lst;
	lst->prev = new;
	return(lst);
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
	t_list *tmp = head;
	if (!head)
		return;
	while (tmp->next != head)
	{
		printf("contenu = %d; prev = %d; next = %d\n", tmp->value, tmp->prev->value, tmp->next->value);
		tmp = tmp->next;
	}
	printf("contenu = %d; prev = %d; next = %d\n", tmp->value, tmp->prev->value, tmp->next->value);
}

