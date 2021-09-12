#include "includes/minishell.h"

char	**split_sa2(char *line, char sa[2])
{
	char	**tokens;
	int		i;
	int		argflag;

	i = 0;
	argflag = 0;
	while (line[i])
	{
		if ((line[i] == sa[0] || line[i] == sa[1]) && line[i + 1])
			argflag = 1;
		i++;
	}
	if (argflag == 1)
		tokens = ft_split2(line, sa);
	else
	{
		tokens = malloc(sizeof(char *) * 2);
		tokens[0] = line;
		tokens[1] = NULL;
	}
	return (tokens);
}

int	check_extra(char *str, int i)
{
	if (str[i + 2] == '>' || str[i + 2] == '<')
	{
		if (str[i + 3] == '>' || str[i + 3] == '<')
		{
			printf("msh: syntax error near unexpected token `>>'\n");
			return (1);
		}
		printf("msh: syntax error near unexpected token `>'\n");
		return (1);
	}
	else
		return (0);
}