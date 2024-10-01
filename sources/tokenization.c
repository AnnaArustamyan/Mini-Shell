#include "../includes/minishell.h"
#include <stdio.h>

int check_token(int c)
{
	if (c == '|')
		return (PIPE);
	if (c == '>')
		return (GREAT);
	if (c == '<')
		return (LESS);
	return (0);
}

int handle_token(char *str, t_lexer **lexer, int i)
{
	t_token	token;

	token = check_token(str[i]);
	if(token == GREAT && str[i + 1] == GREAT)
	{
		create_and_add_to_list(NULL, GREAT_GREAT, lexer);
		return (2);
	}
	else if(token == LESS && str[i + 1] == LESS)
	{
		create_and_add_to_list(NULL, LESS_LESS, lexer);
		return (2);
	}
	else if(token)
	{
		create_and_add_to_list(NULL, token, lexer);
		return (1);
	}
	return (0);
}

int handle_word(char *str, t_lexer **lexer, int i)
{
	int		j;
	char	*word;

	j = i;
	while (str[j] && !is_whitespace(str[j]) && !check_token(str[j]))
		j++;
	word = ft_substr(str, i, j - i);
	create_and_add_to_list(word, 0, lexer);

	return (j - i);
}

void	lexer(char *str, t_lexer **lexer)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_whitespace(str[i]))
		{
			printf("BBB\n");
			i += skip_spaces(str, i);
		}
		else if (check_token(str[i]))
			i += handle_token(str, lexer, i);
		else
		{
			printf("AAAA\n");
			i += handle_word(str, lexer, i);
		}
	}
}

void	print_list(t_lexer *list)
{
	t_lexer	*current;

	current = list;
	while (current)
	{
		printf("%s         %d\n", current->str, current->token);
		//printf("%s\n", current->next->str);
		current = current->next;
	}
}							
int main (int argc, char **argv)
{
	t_lexer	*lexero = NULL;
	//lexero = new_element("hello", 0);
	//lexero->next = new_element("world", 0);
	//print_list(lexero);
	lexer(argv[1], &lexero);
	print_list(lexero);
}

