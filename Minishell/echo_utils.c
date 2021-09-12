#include "includes/minishell.h"

int	is_env(char *s)
{
	if (s[0] == '$')
		return (1);
	return (0);
}

int	parse_env(char *s, t_list **envp_list)
{
	char	*tmp;
	int		i;
	int		j;
	t_list	*point_to_list;

	tmp = malloc((ft_strlen(s) * sizeof(char)) - 1);
	i = 1;
	j = 0;
	while (s[i])
	{
		tmp[j] = s[i];
		j++;
		i++;
	}
	point_to_list = search_key_list(envp_list, tmp);
	free(tmp);
	if (point_to_list != NULL)
	{
		write(1, point_to_list->value, ft_strlen(point_to_list->value));
		return (1);
	}
	else
		return (0);
}