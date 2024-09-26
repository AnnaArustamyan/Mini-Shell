#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	t_var			*env_lst;
	t_token			*tokens;
	int				status;

	if (start(argc, argv, envp, &env_lst) == 1)
		return (0);
	while (1)
	{
		line = readline("\033[1;32mMinishell$ \033[0m");
		if (!line)
		{
			ft_putstr_fd("exit\n", 1);
			return (EXIT_SUCCESS);
		}
		if (ft_strncmp(line, "", ft_strlen(line)) != 0)
			add_history(line);
		parsing_line(line, &tokens, &env_lst);
		free(line);
		if (check_status(env_lst, &status) == 1)
			break ;
	}
	lst_clear(&env_lst, &free);
	return (status);
}