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

typedef struct s_var
{
	char			*name;
	char			*value;
	char			meaning;
	int				status;
	struct s_var	*next;
}					t_var;

typedef struct s_token
{
	char			type;
	char			*value;
	char			*quote;
	struct s_token	*next;
}					t_token;

# endif