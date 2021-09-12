#include "includes/minishell.h"

int	check_invalid(char *str, int i)
{
	if ((str[i] == '<' && str[i + 1] == '>') \
	|| (str[i] == '>' && str[i + 1] == '<'))
	{
		printf("msh: syntax error near unexpected token `>'\n");
		return (1);
	}
	else
		return (0);
}

void	fill_right(char *str, int i, int j)
{
	g_lobal.redir_mass[j] = 1;
	if (str[i + 1] == '>')
	{
		g_lobal.redir_mass[j] = 2;
		i++;
	}
}

void	fill_redirs(int numredir, char *str)
{
	int	i;
	int	j;

	g_lobal.redir_mass = malloc(sizeof(int) * numredir);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '>')
		{
			fill_right(str, i, j);
			j++;
		}
		if (str[i] == '<')
		{
			g_lobal.redir_mass[j] = 3;
			if (str[i + 1] == '<')
			{
				g_lobal.redir_flag = 4;
				g_lobal.redir_mass[j] = 4;
				i++;
			}
			j++;
		}
	}
}

int	find_redir(char *str)
{
	int	numredir;
	int	i;

	i = -1;
	numredir = 0;
	while (str[++i])
	{
		if (check_invalid(str, i))
			return (1);
		if ((str[i] == '>' && str[i + 1] == '>') \
			|| (str[i] == '<' && str[i + 1] == '<'))
		{
			if (check_extra(str, i))
				return (1);
			g_lobal.redir_flag = 1;
			i += 2;
		}
		else if (str[i] == '>' || str[i] == '<')
			g_lobal.redir_flag = 1;
		numredir++;
	}
	if (g_lobal.redir_flag != 0)
		fill_redirs(numredir, str);
	return (0);
}

void	read_empty(char *buf)
{
	while (true)
	{
		buf = readline("> ");
		if (cmd_compare(buf, g_lobal.redir_toks[0]) == 0)
			exit(127);
	}
}