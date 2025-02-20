/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:29:09 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/20 15:39:41 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *new_node;
	t_list *head;
	t_list *head2;
	head2 = NULL;
	int i;
	
	i = 1;
	head = NULL;
	while (i < argc)
	{
		new_node = ft_lstnew(argv[i]);
		head = ft_lstadd_back(head, new_node);
		//head = ft_lstadd_front(&head, new_node);		
		i++;
	}
	printf("----Add back----\n");
	print_list(head);
	printf("Size de head = %d\n", ft_lstsize(head));
	print_list(head);
	swap_a(&head);
	printf("----Cigarette After Swap----\n");
	print_list(head);
	//printf("----after_push/head2----\n");
	// head2 = ft_lstadd_front(&head2, new_node = ft_lstnew("111"));
	// ft_lstadd_front(&head2, new_node = ft_lstnew("222"));
	push_a(&head, &head2);
	push_a(&head, &head2);
	push_a(&head, &head2);
	push_a(&head, &head2);
	printf("----HEAD 2 APRES PUSH----\n");
	print_list(head2);
	printf("----HEAD APRES PUSH----\n");
	print_list(head);
	
	rotate_a(&head);
	printf("----HEAD APRES rotate----\n");
	print_list(head);
	reverse_rotate_a(&head);
	printf("----HEAD APRES REVERSErotate----\n");
	print_list(head);
	printf("\nDans l'ordre 1=OUI 0=NON    %d\n", control(head));
	ft_lstclear(&head);
	ft_lstclear(&head2);
	return(0);
}