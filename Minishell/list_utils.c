#include "includes/minishell.h"

size_t	count_elem_in_list(t_list **envp_list)
{
	t_list	*tmp;
	size_t	qty_elem;

	qty_elem = 0;
	tmp = *envp_list;
	while (tmp != NULL)
	{
		qty_elem++;
		tmp = tmp->next;
	}
	return (qty_elem);
}


void	clean_envp_list(t_list **begin_list)
{
	t_list	*clean;

	clean = NULL;
	while (*begin_list != NULL)
	{
		clean = *begin_list;
		free ((*begin_list)->key);
		free ((*begin_list)->sep);
		free ((*begin_list)->value);
		*begin_list = (*begin_list)->next;
		free (clean);
	}
}

t_list	*ft_create_elem(char *key, char *sep, char *value)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->key = key;
	list->sep = sep;
	list->value = value;
	list->next = NULL;
	return (list);
}

void	ft_push_back_list(t_list **list, char *key, char *sep, char *value)
{
	t_list	*new_list;
	t_list	*tmp_pointer;

	new_list = NULL;
	tmp_pointer = NULL;
	new_list = ft_create_elem(key, sep, value);
	if (*list == NULL)
		*list = new_list;
	else
	{
		tmp_pointer = new_list;
		new_list = *list;
		while (new_list->next != NULL)
			new_list = new_list->next;
		new_list->next = tmp_pointer;
	}
}

void	ft_push_next_list(t_list **list, char *key, char *sep, char *value)
{
	t_list	*new_list;

	new_list = NULL;
	new_list = ft_create_elem(key, sep, value);
	if (*list == NULL)
		*list = new_list;
	else
	{
		if ((*list)->next != NULL)
			new_list->next = (*list)->next;
		(*list)->next = new_list;
	}
}


