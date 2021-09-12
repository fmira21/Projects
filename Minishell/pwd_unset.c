#include "includes/minishell.h"

void	pwd(t_list **envp_list)
{
	t_list	*point_to_list;

	point_to_list = search_key_list(envp_list, "PWD");
	if (point_to_list != NULL)
		printf("%s\n", point_to_list->value);
	else
		perror("ERROR: Point_to_list does no exist!\n");
}

void	unset(t_list **envp_list, const char *key)
{
	t_list	*point_to_list;

	point_to_list = NULL;
	point_to_list = search_key_list(envp_list, key);
	if (point_to_list != NULL)
	{
		ft_bzero(point_to_list->key, ft_strlen(point_to_list->key));
		ft_bzero(point_to_list->sep, ft_strlen(point_to_list->sep));
		ft_bzero(point_to_list->value, ft_strlen(point_to_list->value));
	}
	else
		perror("ERROR: Point_to_list does no exist\n");
}
