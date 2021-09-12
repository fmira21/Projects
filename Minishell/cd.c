#include "includes/minishell.h"

char	*malloc_getcwd(void)
{
	size_t	size;
	char	*value;
	char	*buffer;

	size = 1;
	buffer = (char *)malloc(size);
	if (buffer == NULL)
	{
		perror("Error: Can't allocate memory\n");
		exit(0);
	}
	while (TRUE)
	{
		value = getcwd(buffer, size);
		if (value != NULL)
			return (buffer);
		free(buffer);
		buffer = (char *)malloc(++size);
		if (buffer == NULL)
		{
			perror("Error: Can't allocate memory\n");
			exit(0);
		}
	}
}

void	just_cd(char **cmd, t_list **envp_list)
{
	char	*path;
	char	*oldpwd;
	char	*pwd;

	path = malloc_getcwd();
	oldpwd = ft_strjoin("OLDPWD=", path);
	free(path);
	if (chdir(cmd[1]) == -1)
	{
		perror("Error: No such file or directory\n");
		free(oldpwd);
		return ;
	}
	export(envp_list, oldpwd);
	free(oldpwd);
	path = malloc_getcwd();
	pwd = ft_strjoin("PWD=", path);
	free(path);
	export(envp_list, pwd);
	free(pwd);
}

void	cd_with_arg(t_list **envp_list)
{
	char	*path;
	char	*oldpwd;
	char	*pwd;
	t_list	*home;

	path = malloc_getcwd();
	home = search_key_list(envp_list, "HOME");
	oldpwd = ft_strjoin("OLDPWD=", path);
	free(path);
	if (chdir(home->value) == -1)
	{
		perror("Error: No such file or directory\n");
		free(oldpwd);
		return ;
	}
	export(envp_list, oldpwd);
	free(oldpwd);
	path = malloc_getcwd();
	pwd = ft_strjoin("PWD=", path);
	free(path);
	export(envp_list, pwd);
	free(pwd);
}

void	cd(char **cmd, t_list **envp_list)
{
	if (cmd[1])
		just_cd(cmd, envp_list);
	else
		cd_with_arg(envp_list);
}