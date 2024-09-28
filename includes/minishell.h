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
	//char			type;
	char			*value;
	//char			*quote;
	struct s_token	*next;
}					t_token;


int		ft_strlen(char *str);
char	*ft_substr(char *str, int start, int len);
t_token	*ft_lstnew(char *content);
//t_list	*ft_lstlast(t_list *lst);
void	del_list(t_token *head);
//int		ft_lstsize(t_list *lst);
//void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	create_and_add_to_list(char *str, int start, int len, t_token **list);
void	free_list(t_token *list);

#endif
