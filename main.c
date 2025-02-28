/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:29:09 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/28 11:44:55 by mdsiurds         ###   ########.fr       */
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
		i++;
	}
	ft_index(&head);
	if (control(head) != 1 && ft_lstsize(head) < 4)
		algo_three(&head);
	else if (!control(head) && ft_lstsize(head) < 6)
		algo_five(&head, &head2);
	else if (!control(head) && ft_lstsize(head) >= 6 && ft_lstsize(head) < 151)
	{
		big_algo(&head, &head2, create_block(&head, 3.5));// 3.5!! pour 100 / 8.6!! pour 500 
		big_algo_back_to_head(&head, &head2);
	}
	else if (!control(head) && ft_lstsize(head) >= 151)
	{
		big_algo(&head, &head2, create_block(&head, 8.6));
		big_algo_back_to_head(&head, &head2);
	}
	ft_lstclear(&head);
	ft_lstclear(&head2);
	if (argvsplit)
		free_argv(argvsplit);
	return(0);	
}
