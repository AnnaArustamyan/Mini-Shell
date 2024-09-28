#include "../includes/minishell.h"

t_token	*ft_lstnew(char *value)
{
	t_token	*new_elem;

	new_elem = (t_token *)malloc(sizeof(t_token));
	if (!new_elem)
		return (NULL);
	new_elem->value = value;
	new_elem->next = NULL;
	return (new_elem);
}

void free_list(t_token *list)
{
    t_token *current;
    t_token *next;

    current = list;
    while (current)
    {
        next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
}

// int	ft_lstsize(t_token *lst)
// {
// 	int		count;

// 	count = 0;
// 	while (lst)
// 	{
// 		lst = lst->next;
// 		count++;
// 	}
// 	return (count);
// }

// t_token	*ft_lstlast(t_token *lst)
// {
// 	if (lst)
// 	{
// 		while (lst->next)
// 			lst = lst->next;
// 		return (lst);
// 	}
// 	return (0);
// }

void	del_list(t_token *head)
{
	t_token	*current;
	t_token	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	head = NULL;
}
