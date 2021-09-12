#include "includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_list	*envp_list;
	int		status;

	envp_list = NULL;
	(void)argc;
	(void)argv;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	get_envp(envp, &envp_list, 0);
	status = msh_loop(&envp_list);
	clean_envp_list(&envp_list);
	return (status);
}
