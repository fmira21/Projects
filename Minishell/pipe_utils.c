#include "includes/minishell.h"

int	ignore_quotes(char c)
{
	if (c == '"' || c == '\'' || c == '\\')
		return (1);
	return (0);
}

void	single_command(char **cmds, char *command, t_list **envp_list)
{
	g_lobal.is_pipe = 0;
	g_lobal.is_inter = 1;
	cmds = split_comands_by_token_without_quotes(command, 0);
	cmd_parser(envp_list, cmds);
}

void	operate_pipefds(int i)
{
	if (i != 0)
	{
		dup2(g_lobal.input, 0);
		close(g_lobal.input);
	}
	if (i != g_lobal.pipe_length - 1)
		dup2(g_lobal.pipefds[1], 1);
	close(g_lobal.pipefds[0]);
	close(g_lobal.pipefds[1]);
}

void	pipe_children(char **cmds, char **pipeline, t_list **envp_list)
{
	int	i;

	i = -1;
	while (++i < g_lobal.pipe_length)
	{
		g_lobal.str_buf = ignore_spaces(pipeline[i]);
		pipe(g_lobal.pipefds);
		g_lobal.pipe_pids[i] = fork();
		if (!(g_lobal.pipe_pids[i]))
		{
			operate_pipefds(i);
			cmds = split_comands_by_token_without_quotes(g_lobal.str_buf, 0);
			g_lobal.pipe_status = cmd_parser(envp_list, cmds);
			exit(127);
		}
		if (i != 0)
			close(g_lobal.input);
		close(g_lobal.pipefds[1]);
		g_lobal.input = g_lobal.pipefds[0];
		if (g_lobal.str_buf)
			free (g_lobal.str_buf);
	}
}

void	wait_children(void)
{
	int	i;

	i = 0;
	g_lobal.wait = 0;
	while (g_lobal.wait != -1)
	{
		g_lobal.wait = waitpid(g_lobal.pipe_pids[i],
				&g_lobal.pipe_status, 0);
		if (WIFEXITED(g_lobal.pipe_status))
			g_lobal.proc_status = WEXITSTATUS(g_lobal.pipe_status);
		i++;
	}
}