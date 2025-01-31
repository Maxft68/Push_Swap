/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:41:30 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/01/31 19:13:34 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list *ft_lstnew(void *content)
{
	t_list *new;
	
	new = malloc(sizeof(t_list));
	if(!new)
		return(NULL);
	new->content = content;
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
	if(temp->next == NULL) //deuxieme node uniquement
	{
		temp->next = new;
		return(lst);
	}
	while(temp->next != lst )
	{
		temp = temp->next;
	}
	temp->next = new;
	new->prev = temp;
	new->next = lst;
	// lst->prev = new;
	return(lst);
}

int main()
{
	t_list *head;
	t_list *bidule1;
	t_list *tmp;
	
	head = ft_lstnew("hello");
	bidule1 = ft_lstnew("bidule1");
	head = ft_lstadd_back(head, bidule1);
	
	tmp = malloc(sizeof(t_list));
	if(!tmp)
		return(0);
	tmp = head;
	while(tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
		// if(tmp->next == head)
		// 	printf("%s\n", (char *)tmp->content);
	}
}

// t_list *ft_lstadd_front(t_list **lst, t_list *new)
// {
	
// }
// int ft_lstsize(t_list *lst)
// {
	
// }
// void ft_lstdelone(t_list *lst, void (*del)(void*))
// {
	
// }
// void ft_lstclear(t_list **lst, void (*del)(void*))
// {
	
// }

/* main pour add back*/

//int main()
//{
	// t_list *toto;
	// t_list *toto2;
	// t_list *tmp;
	
	// //toto = ft_lstnew(argv[1]);
	// toto = ft_lstnew("hello");
	// printf("%s\n", (char *)toto->content);
	// printf("%p\n", (char *)toto->next); // = NULL car pas encore creer

	// toto2 = ft_lstnew("hello454");
	// printf("%s\n", (char *)toto2->content);
	// printf("%p\n", (char *)toto2->next);// = NULL car pas encore creer
	// toto->next = toto2; // defini que le next de toto cest toto2
	// printf("%p\n", toto2); // = toto->next
	// printf("%p\n", (char *)toto->next); // = toto2

	// printf("%s\n", (char *)toto->next->content); // content du next de toto / donc content de toto2

	// tmp = toto; //defini une temp pour pas se deplacer avec toto
	// while(tmp != NULL) // se deplace dans les nodes tant qu'il y en a 
	// {
	// 	printf("%s\n", (char *)tmp->content); // = content de toto
	// 	tmp = tmp->next; // = toto2
	// }
	// printf("%s\n", (char *)toto->content); // = content de toto
//}


/* main pour add back*/
/*
int main()
{
	t_list *toto;
	t_list *tmp;
	
	toto = NULL;
	ft_lstadd_back(&toto, ft_lstnew("hello"));
	ft_lstadd_back(&toto, ft_lstnew("hello454"));
	
	tmp = toto;
	while(tmp != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	=
}
*/