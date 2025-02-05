/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:41:30 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/05 17:39:43 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
	
typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;



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

t_list *ft_lstnew(char *the_value, t_list **head, t_list **head2)
{
	t_list *new;
	
	new = malloc(sizeof(t_list));
	if(!new)
		return(ft_lstclear(head),ft_lstclear(head2), NULL);
	new->value = atoi(the_value);
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


t_list *ft_lstadd_front(t_list **from, t_list **new_lst)
{
	t_list *temp_new;
	t_list *temp_from;
	
	temp_new = *new_lst;
	temp_from = *from;
	if((*new_lst)->next == *new_lst) //deuxieme node uniquement
	{
		temp_from->prev->next = temp_from->next; //referme la chaine sans push
		temp_from->next->prev = temp_from->prev; //referme la chaine sans push
		*from = temp_from->next;
		temp_from->next = *new_lst;
		temp_from->prev = *new_lst;
		(*new_lst)->prev->next = temp_from;
		(*new_lst)->prev = temp_from;
		*new_lst = temp_from;

		return(*new_lst);
	}
	else
	{
		t_list *next_lst;
		next_lst = (*new_lst)->next;
		t_list *last;
		last = (*new_lst)->prev;
		
		//from->next = (*new_lst)->next;
		next_lst->prev->prev = temp_from;
		
		
		
		
		
		*new_lst = temp_from;
	}
	return(*new_lst);
}

// void ft_push(t_list *lst_sent, t_list *lst_to_received)
// {
// 	if (!lst_sent)
// 		return;
// 	ft_lstadd_front
	
	
// }

t_list *first_push(t_list **lst_sent) // stack B empty
{	
	
	t_list *new_stack;
	
	new_stack = NULL;
	
	new_stack = *lst_sent;
	
	*lst_sent = (*lst_sent)->next;
	(*lst_sent)->prev->prev->next = *lst_sent; //extraction
	(*lst_sent)->prev = (*lst_sent)->prev->prev; //extraction
	new_stack->next = new_stack; //boucle sur sois meme
	new_stack->prev = new_stack; //boucle sur sois meme
	return (new_stack);
}
int main()
{
	
	t_list *head;
	//t_list *bidule1;
	t_list *tmp;
	t_list *tmp2;
	t_list *i;
	t_list *j;
	t_list *k;
	t_list *l;
	t_list *head2;

	head2 = NULL;
	char *un = "1";
	char *deux = "2";
	char *trois = "3";
	char *quatre = "4";
	char *cinq = "5";
	//char *six = "6";
	
	
	head = ft_lstnew(un, &head, &head2);
	i = ft_lstnew(deux, &head, &head2);
	head = ft_lstadd_back(head, i);
	j = ft_lstnew(trois, &head, &head2);
	head = ft_lstadd_back(head, j);
	k = ft_lstnew(quatre, &head, &head2);
	head = ft_lstadd_back(head, k);
	l = ft_lstnew(cinq, &head, &head2);
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
		printf("contenue = %d;", tmp->value);
		printf(" prev = %d;",tmp->prev->value);
		printf(" next = %d\n",tmp->next->value);
		tmp = tmp->next;
		if(tmp->next == head)
		{
			printf("contenue = %d;", tmp->value);
			printf(" prev = %d;", tmp->prev->value);
			printf(" next = %d\n", tmp->next->value);
		}
	}
	printf("taille de la liste = %d\n", ft_lstsize(head));
	
	if (head == NULL)
		printf("LISTE VIDE!! \n");
	
	
	head2 = first_push(&head);
	printf("contenueNEW = %d;", head2->value);
	printf(" prevNEW = %d;", head2->prev->value);
	printf(" nextNEW = %d\n", head2->next->value);
	printf("taille de la liste2 = %d\n", ft_lstsize(head2));
	printf("taille de la liste = %d\n", ft_lstsize(head));
	tmp = head;
	while(tmp->next != head)
	{
		printf("contenue = %d;", tmp->value);
		printf(" prev = %d;",tmp->prev->value);
		printf(" next = %d\n",tmp->next->value);
		tmp = tmp->next;
		if(tmp->next == head)
		{
			printf("contenue = %d;", tmp->value);
			printf(" prev = %d;", tmp->prev->value);
			printf(" next = %d\n", tmp->next->value);
		}
	}
	ft_lstadd_front(&head, &head2); //2e node dans head2
	ft_lstadd_front(&head, &head2); //3e node
	printf("------APRESFRONT------\n");
	printf("taille de la liste = %d\n", ft_lstsize(head));
	tmp = head;
	while(tmp->next != head)
	{
		printf("contenuehead = %d;", tmp->value);
		printf(" prev = %d;",tmp->prev->value);
		printf(" next = %d\n",tmp->next->value);
		tmp = tmp->next;
		if(tmp->next == head)
		{
			printf("contenuehead = %d;", tmp->value);
			printf(" prev = %d;", tmp->prev->value);
			printf(" next = %d\n", tmp->next->value);
		}
	}
	printf("taille de la liste2 = %d\n", ft_lstsize(head2));
	tmp2 = head2;
	while(tmp2->next != head2)
	{
		printf("contenue2 = %d;", tmp2->value);
		printf(" prev = %d;",tmp2->prev->value);
		printf(" next = %d\n",tmp2->next->value);
		tmp2 = tmp2->next;
		if(tmp2->next == head2)
		{
			printf("contenue = %d;", tmp2->value);
			printf(" prev = %d;", tmp2->prev->value);
			printf(" next = %d\n", tmp2->next->value);
		}
	}
	ft_lstclear(&head);
	ft_lstclear(&head2);
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
	// printf("%s\n", toto->content);
	// printf("%p\n", toto->next); // = NULL car pas encore creer

	// toto2 = ft_lstnew("hello454");
	// printf("%s\n", toto2->content);
	// printf("%p\n", toto2->next);// = NULL car pas encore creer
	// toto->next = toto2; // defini que le next de toto cest toto2
	// printf("%p\n", toto2); // = toto->next
	// printf("%p\n", toto->next); // = toto2

	// printf("%s\n", toto->next->content); // content du next de toto / donc content de toto2

	// tmp = toto; //defini une temp pour pas se deplacer avec toto
	// while(tmp != NULL) // se deplace dans les nodes tant qu'il y en a 
	// {
	// 	printf("%s\n", tmp->content); // = content de toto
	// 	tmp = tmp->next; // = toto2
	// }
	// printf("%s\n", toto->content); // = content de toto
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
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	=
}
*/