#include minishell.h

void	token(char *str, t_token **list)
{
	split_space(str, list);
}

void	split_space(char *str, t_token **list)
{
	int	i;
	int	start;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		start = i;
		while (str[i] != ' ')
		{
			i++;
			create_and_add_to_list(str, start, i - start, list);
			start = i + 1;
		}
	}
}

void	create_and_add_to_list(char *str, int start, int len, t_token **list)
{
	t_token *newnode;
	t_token	*current;
	t_token	*head;
	
	head = *list;
	current = *list;
	while (*list && **list)
		current = current->next;
	newnode = create_node(ft_substr(str, start, len));
	if (!newnode)
		lst_clear(list);
	if (!head)
		newnode = head;
	else
		current->next = newnode;
}

t_token	*create_node(char *value)
{
	t_token *new_node;

	new_node = malloc(sizeof(t_token));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}