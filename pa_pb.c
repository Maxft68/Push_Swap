/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:42:27 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/18 21:45:28 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **from_b, t_list **to_a)
{
	if (!from_b || !*from_b)
		return;
	// if (!to_a || !*to_a)
	// {
		
	// }
	t_list *new_a;
	new_a = *from_b;
	//ft_del_one(from_b);
	printf("-------avantPUSH-------\n");
	print_list(*from_b);
	ft_lstadd_front(to_a, new_a);
	printf("-------apresPUSH-------\n");
	print_list(*from_b);
}