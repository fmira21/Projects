#include "includes/minishell.h"

void	echo_n(char **command)
{
	int	i;
	int	argcount;

	i = 2;
	argcount = 0;
	while (command[i])
	{
		argcount++;
		i++;
	}
	if (argcount == 0)
		return ;
	i = 2;
	argcount++;
	while (i < argcount)
	{
		ft_putstr(command[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putstr(command[argcount]);
}

void	check_envs(char *s, t_list **envp_list)
{
	if (is_env(s) == 1)
	{
		if (parse_env(s, envp_list) == 1)
			ft_putchar(' ');
	}
	else
	{
		ft_putstr(s);
		ft_putchar(' ');
	}
}

void	echo_conv(char **command, t_list **envp_list)
{
	int	i;
	int	argcount;

	i = 0;
	argcount = 0;
	while (command[++i])
		argcount++;
	if (argcount == 0)
	{
		ft_putchar('\n');
		return ;
	}
	i = 0;
	while (++i < argcount)
		check_envs(command[i], envp_list);
	if (is_env(command[i]) == 1)
	{
		parse_env(command[i], envp_list);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr(command[argcount]);
		ft_putchar('\n');
	}
}

void	msh_echo(char **command, t_list **envp_list)
{
	int	i;

	i = 1;
	while (command[i])
		i++;
	if (i == 1)
		echo_conv(command, envp_list);
	else
	{
		if (ft_strncmp(command[1], "-n", ft_strlen(command[1])) == 0)
			echo_n(command);
		else if ((ft_strncmp(command[1], "\\-n", ft_strlen(command[1])) == 0) \
				|| (ft_strncmp(command[1], "\"-n\"", ft_strlen(command[1])) == 0))
			return ;
		else
			echo_conv(command, envp_list);
	}
}