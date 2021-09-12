#include "includes/minishell.h"

int	exec_command(int status, char **commands)
{
	while (*g_lobal.path_value != NULL)
	{
		g_lobal.statint = stat(*g_lobal.path_value, &g_lobal.buf);
		if (g_lobal.statint != -1)
		{
			status = execve(*g_lobal.path_value, commands, g_lobal.envp_mass);
			break ;
		}
		g_lobal.path_value++;
	}
	if (g_lobal.statint == -1)
		perror("Error: Command not found\n");
	exit (127);
	return (status);
}

void	init_exec_commands(t_list *path, char *command, t_list **envp_list)
{
	g_lobal.path_value = ft_split(path->value, ':');
	g_lobal.path_value = join_str_to_each_str_double_mass
		(g_lobal.path_value, "/", AFTHER);
	g_lobal.path_value = join_str_to_each_str_double_mass
		(g_lobal.path_value, command, AFTHER);
	g_lobal.envp_mass = malloc_dubble_mass_or_exit
		(count_elem_in_list(envp_list));
	g_lobal.envp_mass = fill_double_mas_from_list(envp_list, count_elem_in_list
			(envp_list), g_lobal.envp_mass);
}

int	parent_exec(int status, int pid)
{
	waitpid(pid, &status, 0);
	g_lobal.proc_status = 127;
	return (status);
}

int	search_of_command(char **cmd, t_list **envp_list)
{
	t_list		*path;
	char		**commands;
	int			pid;
	int			status;
	char		*command;

	status = 0;
	commands = cmd;
	command = cmd[0];
	path = search_key_list(envp_list, "PATH");
	init_exec_commands(path, command, envp_list);
	if (path == NULL)
		perror("Error: PATH doesn't exist!\n");
	if (pars_of_command(commands) != NULL)
		command = pars_of_command(commands);
	pid = fork();
	if (pid == 0)
		status = exec_command(status, commands);
	else
		status = parent_exec(status, pid);
	free_double_massive(g_lobal.path_value);
	free_double_massive(g_lobal.envp_mass);
	return (status);
}
