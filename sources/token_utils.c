#include "minishell.h"

char	*ft_substr(char *str, int start, int len)
{
	int		i;
	int		j;
	char	*res;

	if (!str)
		return ("");
	if (len <= ft_strlen(str))
		res = malloc(len + 1);
	else
		res = malloc(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i >= start && j < len)
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
