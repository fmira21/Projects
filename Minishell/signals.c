#include "includes/minishell.h"

void	handle_c0(void)
{
	write(1, "\n", 1);
	write (1, "msh > ", 6);
	rl_replace_line("", 0);
}

void	handle_c1(void)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_c2(void)
{
	write(1, "\n", 1);
	rl_on_new_line();
}

void	sig_handler(int sig)
{
	if (sig == SIGINT && g_lobal.is_pipe == 0 && g_lobal.is_inter == 0)
		handle_c0();
	else if (sig == SIGINT && g_lobal.is_pipe == 0 && g_lobal.is_inter == 1)
		handle_c1();
	else if (sig == SIGINT && g_lobal.is_pipe == 1 && g_lobal.is_inter == 1)
		handle_c2();
	if (sig == SIGQUIT && g_lobal.is_pipe == 0 && g_lobal.is_inter == 1)
		printf("Quit: 3\n");
	else if (sig == SIGQUIT && g_lobal.is_pipe == 1 && g_lobal.is_inter == 1)
		rl_on_new_line();
	else if (sig == SIGQUIT && g_lobal.is_pipe == 0 && g_lobal.is_inter == 0)
		rl_redisplay();
}
