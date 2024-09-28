#include "../includes/minishell.h"
#include <stdio.h>

// void	token(char *str, t_token **list)
// {
// 	split_space(str, list);
// }

void	list_init(char *str, t_token **list)
{
	int	i;
	int	start;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		start = i;
		while (str[i] && str[i] != ' ')
			i++;
		if (i > start)
			create_and_add_to_list(str, start, i - start, list);
	}
}

void	create_and_add_to_list(char *str, int start, int len, t_token **list)
{
	t_token	*newnode;
	t_token	*current;

	newnode = ft_lstnew(ft_substr(str, start, len));
	if (!newnode)
	{
		del_list(*list);
		return ;
	}
	if (*list == NULL)
		*list = newnode;
	else
	{
		current = *list;
		while (current->next)
			current = current->next;
		current->next = newnode;
	}
}


void	print_list(t_token *list)
{
	t_token	*current;

	current = list;
	while (current)
	{
		printf("%s\n", current->value);
		current = current->next;
	}
}

// int	main(int argc, char **argv)
// {
// 	t_token *list;
// 	list = NULL;
// 	list_init(argv[1], &list);
// 	print_list(list);
// 	free_list(list);
// }
