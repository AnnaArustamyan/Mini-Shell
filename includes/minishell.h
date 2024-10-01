# ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum s_token
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_token;

typedef struct s_lexer
{
	char    	*str;
	t_token        token;
	int		index;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;


int check_token(int c);
int handle_token(char *str, t_lexer **lexer, int i);
int handle_word(char *str, t_lexer **lexer, int i);
void lexer(char *str, t_lexer **lexer);

int is_whitespace(char c);
int skip_spaces(char *str, int i);

void create_and_add_to_list(char *str, t_token token, t_lexer **list);
void clear_lexer(t_lexer **head);
t_lexer *new_element(char *str, t_token token);
void el_add_back(t_lexer **head, t_lexer *new);

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strlen(char *str);
char	*ft_substr(char *str, int start, int len);
void	ft_putstr_fd(char *s, int fd);



#endif
