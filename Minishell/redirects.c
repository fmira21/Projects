#include "includes/minishell.h"

void	wait_redir_children(void)
{
	int	i;

	i = 0;
	g_lobal.wait = 0;
	while (g_lobal.wait != -1)
	{
		g_lobal.wait = waitpid(g_lobal.redir_pids[i],
				&g_lobal.redir_status, 0);
		if (WIFEXITED(g_lobal.redir_status))
			g_lobal.proc_status = WEXITSTATUS(g_lobal.redir_status);
		i++;
	}
}

void	exec_redir_children(char **str, char *buf, t_list **envp_list)
{
	int	i;

	i = -1;
	g_lobal.j = 0;
	while (++i < g_lobal.redir_length)
	{
		pipe(g_lobal.redirfds);
		g_lobal.redir_pids[i] = fork();
		if (!(g_lobal.redir_pids[i]))
		{
			if (i == 0)
			{
				if (g_lobal.redir_length < 2 && g_lobal.redir_mass[0] == 4)
					read_empty(buf);
				else
					continue ;
			}
			else
				exec_nonempty(str, buf, envp_list, i);
		}
		else
			wait_redir_children();
		g_lobal.j++;
	}
}

void	redir_parse(char **cmds, t_list **envp_list)
{
	int		i;
	int		j;
	char	**str;
	char	*buf;

	g_lobal.redir_toks = split_sa2(cmds[0], "><");
	i = -1;
	j = 0;
	buf = NULL;
	str = NULL;
	g_lobal.redir_length = 0;
	while (g_lobal.redir_toks[++i])
	{
		g_lobal.redir_toks[i] = ignore_spaces(g_lobal.redir_toks[i]);
		g_lobal.redir_length++;
	}
	g_lobal.redir_pids = malloc(sizeof(pid_t) * g_lobal.redir_length);
	exec_redir_children(str, buf, envp_list);
	free(g_lobal.redir_mass);
}

int	redir_detect(char **cmd)
{
	int	status;
	int	i;

	i = -1;
	while (cmd[++i])
		status = find_redir(cmd[i]);
	return (status);
}
