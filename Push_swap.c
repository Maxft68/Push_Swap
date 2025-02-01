/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxoph <maxoph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:16:07 by maxoph            #+#    #+#             */
/*   Updated: 2025/01/29 16:16:08 by maxoph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//#include "libft.h"
//#include "fr_printf.h"
#include <stdio.h>
#include <stdlib.h>
//#include 

typedef struct s_node
{
	int value;
	int index;
	struct s_node *next;
	struct s_node *previous;
} t_node;


t_node *create_node(char *value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if(!node)
	{
		//void free_all_node(&first);
		return (NULL);
	}
	node->value = atoi(value); //mettre ft_atoi plus tard
	node->next = NULL;
	return (node);
}

t_node *create_chain(char **argv)
{
	t_node	*first;
	t_node	*current;
	t_node	*previous;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!first)
		{
			first = create_node(argv[i]);
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
	return (first);
}
int main(int argc, char **argv)
{
	t_node *list;

	if (argc > 1)
	{
		list = create_chain(argv + 1); // Crée la liste chaînée à partir des arguments

		// Parcourir la liste chaînée et afficher les valeurs
		t_node *current = list;
		while (current)
		{
			printf("%d\n", current->value); // Affiche la valeur du nœud courant
			current = current->next; // Passe au nœud suivant
		}
	}
	return (0);
}