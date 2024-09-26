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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}