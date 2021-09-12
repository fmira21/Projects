#include "includes/minishell.h"

int	cmd_parser(t_list **envp_list, char **command)
{
	int	status;
	int	i;

	i = 1;
	status = 0;
	if (cmd_compare(command[0], "echo") == 0)
		msh_echo(command, envp_list);
	else if (cmd_compare(command[0], "env") == 0)
		env(envp_list);
	else if (cmd_compare(command[0], "unset") == 0)
		exec_unset(command, envp_list, i);
	else if (cmd_compare(command[0], "export") == 0)
		exec_export(command, envp_list, i);
	else if (cmd_compare(command[0], "pwd") == 0)
		pwd(envp_list);
	else if (cmd_compare(command[0], "cd") == 0)
		cd(command, envp_list);
	else if (cmd_compare(command[0], "$?") == 0)
		printf("%i\n", g_lobal.proc_status);
	else if (cmd_compare(command[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	else
		status = search_of_command(command, envp_list);
	return (status);
}