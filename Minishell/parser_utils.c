#include "includes/minishell.h"

char	**split_sa(char *line, char sa)
{
	char	**tokens;
	int		i;
	int		argflag;

	i = 0;
	argflag = 0;
	while (line[i])
	{
		if (line[i] == sa && line[i + 1])
			argflag = 1;
		i++;
	}
	if (argflag == 1)
		tokens = ft_split(line, sa);
	else
	{
		tokens = malloc(sizeof(char *) * 2);
		tokens[0] = line;
		tokens[1] = NULL;
	}
	return (tokens);
}

int	cmd_compare(char *s1, char *s2)
{
	if ((ft_strncmp(s1, s2, ft_strlen(s1)) == 0) \
		&& (ft_strlen(s1) == ft_strlen(s2)))
		return (0);
	else
		return (1);
}

void	exec_unset(char **command, t_list **envp_list, int i)
{
	while (command[i] != NULL)
		unset(envp_list, command[i++]);
}

void	exec_export(char **command, t_list **envp_list, int i)
{
	if (command[i] == NULL)
		export(envp_list, command[i]);
	else
		while (command[i] != NULL)
			export(envp_list, command[i++]);
}

char	*ignore_spaces(char const *s)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s[start] && s[start] == ' ')
		start++;
	end = ft_strlen(s) - 1;
	while (end > start && s[end] == ' ')
		end--;
	str = (char *)malloc(sizeof(*s) * (end - start + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end + 1)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
