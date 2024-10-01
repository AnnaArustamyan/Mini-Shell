#include "../includes/minishell.h"

t_lexer	*new_element(char *str, t_token token)
{
	t_lexer	*new;
	static int	index = 0;

	new = (t_lexer *)malloc(sizeof(t_lexer));
	if (!new)
		return (NULL);
	new->str = str;
	new->token = token;
	new->index = index++;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}


void el_add_back(t_lexer **head, t_lexer *new)
{
	t_lexer	*last;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

void create_and_add_to_list(char *str, t_token token, t_lexer **list)
{
	t_lexer	*new;

	new = new_element(str, token);
	if(!new)
		return ;
	el_add_back(list, new);
}

void clear_lexer(t_lexer **head)
{
	t_lexer	*current;
	t_lexer	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
	*head = NULL;
}

