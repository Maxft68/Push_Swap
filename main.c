/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:29:09 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/21 14:46:27 by mdsiurds         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_list *new_node;
	t_list *head;
	t_list *head2;
	char **argvsplit;
	head2 = NULL;
	int i;
	
	i = 1;
	head = NULL;
	argvsplit = NULL;
	if (argc == 2)
	{
		argvsplit = ft_split(argv[1], ' ');
		argv = argvsplit;
		i = 0;
	}
	while (argv[i])
	{
		new_node = ft_lstnew(argv[i]);
		head = ft_lstadd_back(head, new_node);
		//head = ft_lstadd_front(&head, new_node);		
		i++;
	}
	ft_index(&head);
	//printf("----Cigarette Before Three----\n");
	print_list(head);
	
	// if (!control(head) && ft_lstsize(head) < 4)
	// 	algo_three(&head);
	// algo_five(&head, &head2);
	
	//printf("----Cigarette After Three----\n");
	// printf("----Add back----\n");
	// print_list(head);
	// printf("Size de head = %d\n", ft_lstsize(head));
	// print_list(head);
	// swap_a(&head);
	// print_list(head);
	// //printf("----after_push/head2----\n");
	// // head2 = ft_lstadd_front(&head2, new_node = ft_lstnew("111"));
	// // ft_lstadd_front(&head2, new_node = ft_lstnew("222"));
	// push_a(&head, &head2);
	// push_a(&head, &head2);
	// push_a(&head, &head2);
	// push_a(&head, &head2);
	
	// printf("----HEAD 2 APRES PUSH----\n");
	// print_list(head2);
	// printf("----HEAD APRES PUSH----\n");
	// print_list(head);
	
	// rotate_a(&head);
	// printf("----HEAD APRES rotate----\n");
	// print_list(head);
	// reverse_rotate_a(&head);
	// printf("----HEAD APRES REVERSErotate----\n");
	//print_list(head);
	// printf("\nDans l'ordre 1=OUI 0=NON    %d\n", control(head));
	ft_lstclear(&head);
	ft_lstclear(&head2);
	if (argvsplit)
		free_argv(argvsplit);
	return(0);	
}