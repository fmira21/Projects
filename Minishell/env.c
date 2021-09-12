#include "includes/minishell.h"

void	get_envp(char **envp, t_list **envp_list, int index)
{
	char	*pointer_to_sep;
	char	*key;
	char	*value;
	char	*sep;

	pointer_to_sep = NULL;
	key = NULL;
	value = NULL;
	sep = NULL;
	while (envp[index] != NULL)
	{
		pointer_to_sep = ft_strchr(envp[index], '=');
		if (*pointer_to_sep != '=')
			perror("ERROR: Poiter_to_sep does no exist!\n");
		key = get_key(envp[index]);
		sep = get_sep(pointer_to_sep);
		value = get_value(++pointer_to_sep);
		ft_push_back_list(envp_list, key, sep, value);
		index++;
	}
}

void	env(t_list **envp_list)
{
	t_list	*tmp;

	tmp = *envp_list;
	while (tmp != NULL)
	{
		if (tmp->key && tmp->key[0] != '\0' && tmp->sep && tmp->sep[0] != '\0')
		{
			printf("%s", tmp->key);
			printf("%s", tmp->sep);
			if (tmp->value && tmp->value[0] != '\0')
				printf("%s", tmp->value);
			printf("\n");
		}
		tmp = tmp->next;
	}
}