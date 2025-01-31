#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list *ft_lstnew(void *content)
{
	t_list *new;
	
	new = malloc(sizeof(t_list));
	if(!new)
		return(NULL);
	new->content = content;
	new->next = NULL; // = (*new).next
	new->prev = NULL;
	return(new);
}

t_list *ft_lstadd_back(t_list *lst, t_list *new) {
    t_list *temp;

    if (!lst)
        return new;
    temp = lst;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
    return lst;
}

int main() {
    t_list *head;
    t_list *bidule1;
    t_list *tmp;

    head = ft_lstnew("hello");
    bidule1 = ft_lstnew("bidule1");
    head = ft_lstadd_back(head, bidule1);

    tmp = head;
    while (tmp) {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }

    // Libérer la mémoire allouée
    // while (head) {
    //     t_list *next = head->next;
    //     free(head);
    //     head = next;
    // }

    return 0;
}