#include "includes/minishell.h"

int	check_arg(char *arg)
{
	char	*sep;

	if (!arg)
		return (-1);
	if (arg[0] == '_' && arg[1] == '\0')
		return (0);
	sep = ft_strchr(arg, '=');
	if ((ft_isalpha(arg[0]) == 1 || arg[0] == '_') && sep && sep[1])
		return (3);
	else if ((ft_isalpha(arg[0]) == 1 || arg[0] == '_') && sep)
		return (2);
	else if (ft_isalpha(arg[0]) == 1 || arg[0] == '_')
		return (1);
	else
		return (-1);
}

void	push_key_sep_value(t_list **envp_list, char *arg)
{
	t_list	*found_list_elem;
	char	*key;
	char	*sep;
	char	*value;

	key = NULL;
	sep = NULL;
	value = NULL;
	found_list_elem = NULL;
	key = get_key(arg);
	sep = get_sep(ft_strchr(arg, '='));
	value = ft_strchr(arg, '=');
	value = get_value(++value);
	found_list_elem = search_key_list(envp_list, key);
	if (found_list_elem)
	{
		unset(&found_list_elem, key);
		ft_push_next_list(&found_list_elem, key, sep, value);
	}
	else
		ft_push_back_list(envp_list, key, sep, value);
}

void	push_key_sep(t_list **envp_list, char *arg)
{
	t_list	*found_list_elem;
	char	*key;
	char	*sep;
	char	*value;

	key = NULL;
	sep = NULL;
	value = NULL;
	found_list_elem = NULL;
	key = get_key(arg);
	sep = get_sep(ft_strchr(arg, '='));
	found_list_elem = search_key_list(envp_list, key);
	if (found_list_elem)
	{
		unset(&found_list_elem, key);
		ft_push_next_list(&found_list_elem, key, sep, value);
	}
	else
		ft_push_back_list(envp_list, key, sep, value);
}

void	push_key(t_list **envp_list, char *arg)
{
	t_list	*found_list_elem;
	char	*key;
	char	*sep;
	char	*value;

	key = NULL;
	sep = NULL;
	value = NULL;
	found_list_elem = NULL;
	key = get_key(arg);
	found_list_elem = search_key_list(envp_list, key);
	if (found_list_elem)
	{
		unset(&found_list_elem, key);
		ft_push_next_list(&found_list_elem, key, sep, value);
	}
	else
		ft_push_back_list(envp_list, key, sep, value);
}
