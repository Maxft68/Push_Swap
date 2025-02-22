/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:29:09 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/22 01:20:01 by mdsiurds         ###   ########.fr       */
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
	create_block(&head);
	//ft_lstsize(head);
	//printf("----Cigarette Before Three----\n");
	
	// t_list *index_minus = index_min(&head);
	// printf("----Cigarette after minus----\n");
	// print_list(index_minus);
	// printf("----HEAD----\n");
	// print_list(head);
	// printf("----HEAD2----\n");
	// print_list(head2);
	
	if (control(head) != 1 && ft_lstsize(head) < 4)
		algo_three(&head);
	else if (!control(head) && ft_lstsize(head) < 6)
		algo_five(&head, &head2);
	else
		big_algo(&head, &head2);
	// printf("----HEAD----\n");
	// print_list(head);
	// printf("----HEAD2----\n");
	// print_list(head2);
	ft_lstclear(&head);
	ft_lstclear(&head2);
	if (argvsplit)
		free_argv(argvsplit);
	return(0);	
}