/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:58:34 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/01/31 17:25:08 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int value;
	// int index;
	struct s_node *next;
	struct s_node *prev;
}			 t_node;

void print_all_value(t_node **first)
{
	t_node *current = *first;
	while(current)
	{
		printf("%d", current->value); // a remplacer par ft_printf
		current = current->next;
	}
	printf("end of node"); // a remplacer par ft_printf
}

t_node *create_node(char *value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if(!node)
		// clear_all_node
		return (NULL);
	node->value = atoi(value); // atoi a modifier par la mienne
	node->next = NULL;
	node->prev = NULL;
	return (node);
}


t_node	*create_chain(char **argv)
{
	t_node	*first;
	t_node	*current;
	t_node	*previous;
	int		i;

	i = 0;
	while (argv[i])
	{
		t_node *current = *first;
		{
			first = malloc(sizeof(t_node));
			first->value = atoi(argv[i]);
			first->next = NULL;
			current = first;
		}
		else
		{
			current = create_node(argv[i]);
			previous->next = current;
		}
		previous = current;
		i++;
	}
	print_all_value(&first);
	return(first);
}
int main(int argc, char **argv)
{
	if(argc < 2)
		return(0);
	int i;
	i = 0;
	create_chain(&argv);	
}

