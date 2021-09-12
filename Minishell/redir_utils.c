#include "includes/minishell.h"

void	exec_single_right(char **str, t_list **envp_list, int i)
{
	g_lobal.redirfds[1] = open(g_lobal.redir_toks[i],
			O_CREAT | O_TRUNC | O_WRONLY, 0644);
	dup2(g_lobal.redirfds[1], 1);
	close(g_lobal.redirfds[1]);
	str = split_sa(g_lobal.redir_toks[0], ' ');
	cmd_parser(envp_list, str);
	exit (127);
}

void	exec_double_right(char **str, t_list **envp_list, int i)
{
	g_lobal.redirfds[1] = open(g_lobal.redir_toks[i],
			O_CREAT | O_APPEND | O_WRONLY, 0644);
	dup2(g_lobal.redirfds[1], 1);
	close(g_lobal.redirfds[1]);
	str = split_sa(g_lobal.redir_toks[0], ' ');
	cmd_parser(envp_list, str);
	exit (127);
}

void	exec_single_left(char **str, t_list **envp_list, int i)
{
	g_lobal.redirfds[0] = open(g_lobal.redir_toks[i],
			O_RDONLY, 0644);
	dup2(g_lobal.redirfds[0], 0);
	close(g_lobal.redirfds[0]);
	str = split_sa(g_lobal.redir_toks[0], ' ');
	cmd_parser(envp_list, str);
	exit (127);
}

void	exec_double_left(char *buf, char **str, t_list **envp_list)
{
	g_lobal.redirfds[0] = open("heredoc",
			O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (true)
	{
		buf = readline("> ");
		if (cmd_compare(buf, g_lobal.redir_toks[1]) == 0)
		{
			close (g_lobal.redirfds[0]);
			break ;
		}
		buf[ft_strlen(buf)] = '\n';
		write(g_lobal.redirfds[0], buf, ft_strlen(buf));
	}
	g_lobal.redirfds[0] = open("heredoc", O_RDONLY, 0644);
	dup2(g_lobal.redirfds[0], 0);
	close(g_lobal.redirfds[0]);
	str = split_sa(g_lobal.redir_toks[0], ' ');
	cmd_parser(envp_list, str);
	unlink("heredoc");
	exit (127);
}

void	exec_nonempty(char **str, char *buf, t_list **envp_list, int i)
{
	if (g_lobal.redir_mass[g_lobal.j] == 1)
		exec_single_right(str, envp_list, i);
	else if (g_lobal.redir_mass[g_lobal.j] == 2)
		exec_double_right(str, envp_list, i);
	else if (g_lobal.redir_mass[g_lobal.j] == 3)
		exec_single_left(str, envp_list, i);
	else if (g_lobal.redir_mass[g_lobal.j] == 4)
		exec_double_left(buf, str, envp_list);
}
