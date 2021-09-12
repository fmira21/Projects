#include "includes/minishell.h"

char	*dvs_strdup(const char *string, size_t size_string)
{
	char	*destination;
	size_t	qty_symbol;

	qty_symbol = 0;
	destination = NULL;
	if (size_string >= 0)
		destination = (char *)malloc(sizeof(char) * (size_string + 1));
	if (destination == NULL)
	{
		perror("Error: Can't allocate memory\n");
		exit(0);
	}
	while (qty_symbol < size_string)
	{
		destination[qty_symbol] = string[qty_symbol];
		qty_symbol++;
	}
	destination[qty_symbol] = '\0';
	return (destination);
}

char	*get_key(char *envp)
{
	char	*key;
	size_t	size;

	size = 0;
	if (!envp)
		return (NULL);
	while (envp[size] != '=' && envp[size] != '\0')
		size++;
	key = dvs_strdup(envp, size);
	return (key);
}

char	*get_value(char *envp)
{
	char	*value;
	size_t	size;

	size = 0;
	if (!envp)
		return (NULL);
	while (envp[size] != '\0')
		size++;
	value = dvs_strdup(envp, size);
	return (value);
}

char	*get_sep(char *envp)
{
	char	*sep;

	if (!envp)
		return (NULL);
	sep = dvs_strdup(envp, 1);
	return (sep);
}

t_list	*search_key_list(t_list **begin_list, const char *key)
{
	t_list	*tmp;

	tmp = *begin_list;
	if (!key || !(*begin_list))
		return (NULL);
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, key) == SAME)
			return (tmp);
		tmp = (tmp)->next;
	}
	return (NULL);
}