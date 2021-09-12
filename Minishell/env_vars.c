#include "includes/minishell.h"

void	check_empty_elems_and_join_ksv(t_list *tmp_list, char **exp, size_t i)
{
	char	*tmp;

	tmp = NULL;
	if (tmp_list->key != NULL && tmp_list->sep != NULL
		&& tmp_list->value != NULL)
	{
		exp[i] = ft_strjoin(tmp_list->key, tmp_list->sep);
		if (tmp_list->key[0] != '\0' && tmp_list->sep[0] != '\0')
		{
			tmp = exp[i];
			exp[i] = ft_strjoin(exp[i], "\"");
			free(tmp);
		}
		tmp = exp[i];
		exp[i] = ft_strjoin(exp[i], tmp_list->value);
		free(tmp);
		if (tmp_list->key[0] != '\0' && tmp_list->sep[0] != '\0')
		{
			tmp = exp[i];
			exp[i] = ft_strjoin(exp[i], "\"");
			free(tmp);
		}
	}
}

void	check_empty_elems_and_join_ks(t_list *tmp_list, char **exp, size_t i)
{
	char	*tmp;

	tmp = NULL;
	exp[i] = ft_strjoin(tmp_list->key, tmp_list->sep);
	if (tmp_list->key[0] != '\0' && tmp_list->sep[0] != '\0')
	{
		tmp = exp[i];
		exp[i] = ft_strjoin(exp[i], "\"\"");
		free(tmp);
	}
}

void	check_empty_elems_and_join_dec_x(t_list *unused, char **exp, size_t qty)
{
	char	*tmp;
	size_t	index;

	(void) unused;
	index = 0;
	tmp = NULL;
	while (index != qty)
	{
		if (exp[index] != NULL && exp[index][0] != '\0')
		{
			tmp = exp[index];
			exp[index] = ft_strjoin("declare -x ", exp[index]);
			free(tmp);
		}
		index++;
	}
}

char	**malloc_dubble_mass_or_exit(size_t size)
{
	char	**pointer;

	pointer = NULL;
	pointer = (char **)malloc(sizeof(char *) * (size + 1));
	if (pointer == NULL)
	{
		perror("Error: Can't allocate memory\n");
		exit (0);
	}
	pointer[size] = NULL;
	return (pointer);
}

char	**fill_double_mas_from_list(t_list **envp, size_t qty, char **export)
{
	size_t	index;
	t_list	*tmp_list;

	tmp_list = *envp;
	index = 0;
	while (index != qty)
	{
		if (tmp_list->key != NULL && tmp_list->sep != NULL
			&& tmp_list->value != NULL)
			check_empty_elems_and_join_ksv(tmp_list, export, index);
		else if (tmp_list->key != NULL && tmp_list->sep != NULL)
			check_empty_elems_and_join_ks(tmp_list, export, index);
		else if (tmp_list->key != NULL)
			export[index] = dvs_strdup(tmp_list->key, ft_strlen(tmp_list->key));
		else
			perror("Error: Elems empty!\n");
		index++;
		tmp_list = tmp_list->next;
	}
	return (export);
}