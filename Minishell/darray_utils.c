#include "includes/minishell.h"

void	free_double_massive(char **double_massive)
{
	int	index;

	index = 0;
	if (!double_massive)
		return ;
	while (double_massive[index] != NULL)
	{
		free (double_massive[index]);
		index++;
	}
	free (double_massive);
}

void	print_double_massive_char(char **double_massive, size_t size)
{
	size_t	index;

	index = 0;
	if (!double_massive)
		return ;
	while (index != size)
	{
		if (double_massive[index] != NULL && double_massive[index][0] != '\0')
			printf("%s\n", double_massive[index]);
		index++;
	}
}

char	**sort_bubble_double_massive_char(char **keys)
{
	char	*tmp;
	int		current_key;
	int		next_key;

	tmp = NULL;
	current_key = 0;
	next_key = 0;
	if (!keys)
		return (NULL);
	while (keys[++next_key] != NULL)
	{
		if (ft_strcmp(keys[current_key], keys[next_key]) == CHANGE)
		{
			tmp = keys[current_key];
			keys[current_key] = keys[next_key];
			keys[next_key] = tmp;
			current_key = 0;
			next_key = 0;
			continue ;
		}
		current_key += 1;
	}
	return (keys);
}

char	**join_str_to_each_str_double_mass(char **keys, const char *s, int pos)
{
	int		index;
	char	*tmp;

	index = 0;
	tmp = NULL;
	if (!keys)
		return (NULL);
	while (keys[index] != NULL)
	{
		if (pos == BEFORE)
		{
			tmp = keys[index];
			keys[index] = ft_strjoin(s, keys[index]);
			free(tmp);
		}
		else
		{
			tmp = keys[index];
			keys[index] = ft_strjoin(keys[index], s);
			free(tmp);
		}
		index++;
	}
	return (keys);
}