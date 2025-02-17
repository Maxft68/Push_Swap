/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdsiurds <mdsiurds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:22:31 by mdsiurds          #+#    #+#             */
/*   Updated: 2025/02/17 17:25:18 by mdsiurds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void	ft_lstclear(t_list **lst);
void ft_del_one(t_list **head);
int		ft_lstsize(t_list *list);
t_list	*ft_lstnew(char *the_value);
t_list *ft_lstadd_back(t_list *lst, t_list *new);
t_list *ft_lstadd_front(t_list **lst, t_list *new);
void print_list(t_list *head); // inutile a rendre ??

//printf
int		ft_printf(const char *str, ...)__attribute__((format(printf, 1, 2)));
int		ft_putchar(char c);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *s);
int		ft_unsigned(unsigned int x);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_printf(const char *str, ...);
int		ft_putnbr(int n);
int		ft_pointer(unsigned long long x);
int		ft_hexa(unsigned int x, int capital);

#endif