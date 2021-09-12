#include "includes/minishell.h"

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	checker(char *line)
{
	if ((line[0] == ';' && line[1] == ';') \
		|| (line[0] == '|' && line[1] == '|'))
	{
		printf("Error near unexpected token `%c%c\"\n", line[0], line[1]);
		return (1);
	}
	else if (line[0] == ';' || line[0] == '|')
	{
		printf("Error near unexpected token `%c\"\n", line[0]);
		return (1);
	}
	else if (line[0] == '\0')
		return (1);
	else if (line[0] == ' ')
	{
		if (check_spaces(line) == 1)
			return (1);
	}
	return (0);
}

void	init_vars(void)
{
	g_lobal.is_inter = 0;
	g_lobal.is_pipe = 0;
	g_lobal.redir_flag = 0;
	g_lobal.parent = getpid();
}

int	parse_entrypoint(t_list **envp_list, char **pipeline)
{
	int		i;
	char	**cmds;

	g_lobal.pipe_status = 0;
	g_lobal.pipe_length = 0;
	cmds = NULL;
	g_lobal.str_buf = NULL;
	while (pipeline[g_lobal.pipe_length])
		g_lobal.pipe_length++;
	g_lobal.pipe_pids = malloc(sizeof(pid_t) * (g_lobal.pipe_length));
	g_lobal.pipe_pids[g_lobal.pipe_length] = -1;
	i = -1;
	if (g_lobal.pipe_length == 1)
		single_command(cmds, pipeline[0], envp_list);
	else
	{
		g_lobal.is_pipe = 1;
		g_lobal.is_inter = 1;
		pipe_children(cmds, pipeline, envp_list);
		close(g_lobal.input);
		wait_children();
	}
	free(g_lobal.pipe_pids);
	free_double_massive(cmds);
	return (g_lobal.pipe_status);
}

int	msh_loop(t_list **envp_list)
{
	char			**cmds;
	static char		*line;

	while (true)
	{
		init_vars();
		line = readline("msh > ");
		if (!line)
			exit(EXIT_SUCCESS);
		if (checker(line) == 1)
			continue ;
		cmds = split_sa(line, '|');
		redir_detect(cmds);
		if (g_lobal.redir_flag != 0)
			redir_parse(cmds, envp_list);
		else
			parse_entrypoint(envp_list, cmds);
		g_lobal.current = getpid();
		if (g_lobal.current != g_lobal.parent)
			exit(127);
		if (*line && g_lobal.redir_flag != 4)
			add_history(line);
		free_double_massive(cmds);
	}
	return (0);
}
