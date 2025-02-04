/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:41:30 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/04 17:21:56 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

// void ft_push(t_list *lst_sent, t_list *lst_to_received)
// {
// 	if (!lst_sent)
// 		return;
	
	
	
// }

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

int ft_lstsize(t_list *list)
{
	t_list *temp;
	temp = list;
	int i;
	i = 0;
	if (list == NULL)
		return (0);
	while (temp->next != list)
	{
		i++;
		temp = temp->next;
	}
	if (list->next != temp)
		i++;
	return (i);
}

t_list *ft_lstnew(void *value) //(void *value, void *index) ??
{
	t_list *new;
	
	new = malloc(sizeof(t_list));
	if(!new)
		return(NULL);
	new->content = value;
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
		return(lst);
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


// t_list *ft_lstadd_front(t_list **lst, t_list *new)
// {
	
// }

int main()
{
	t_list *head;
	//t_list *bidule1;
	t_list *tmp;
	t_list *i;
	t_list *j;
	t_list *k;
	t_list *l;
	head = ft_lstnew("hello");
	i = ft_lstnew("1node");
	head = ft_lstadd_back(head, i);
	j = ft_lstnew("2node");
	head = ft_lstadd_back(head, j);
	k = ft_lstnew("3node");
	head = ft_lstadd_back(head, k);
	l = ft_lstnew("4node");
	head = ft_lstadd_back(head, l);

	// t_list *head2;
	// t_list *m;
	// t_list *n;
	// t_list *o;
	// //t_list *p;
	// head2 = ft_lstnew("pile2");
	// m = ft_lstnew("coco1");
	// head2 = ft_lstadd_back(head2, m);
	// n = ft_lstnew("coco2");
	// head2 = ft_lstadd_back(head2, n);
	// o = ft_lstnew("coco3");
	// head2 = ft_lstadd_back(head2, o);
	// p = ft_lstnew("coco4");
	// head2 = ft_lstadd_back(head2, p);
	
	tmp = head;
	while(tmp->next != head)
	{
		printf("contenue = %s;", (char *)tmp->content);
		printf(" prev = %s;", (char *)tmp->prev->content);
		printf(" next = %s\n", (char *)tmp->next->content);
		tmp = tmp->next;
		if(tmp->next == head)
		{
			printf("contenue = %s;", (char *)tmp->content);
			printf(" prev = %s;", (char *)tmp->prev->content);
			printf(" next = %s\n", (char *)tmp->next->content);
		}
	}
	printf("taille de la liste = %d\n", ft_lstsize(head));
	ft_lstclear(&head);
	
	if (head == NULL)
		printf("LISTE VIDE!! \n");
	printf("taille de la liste2 = %d\n", ft_lstsize(head));
	
	//printf("taille de la liste = %d\n", ft_lstsize(head));
	return(0);
}


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