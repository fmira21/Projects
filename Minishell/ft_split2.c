#include "includes/minishell.h"

static char	**error_free2(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static unsigned int	get_strings2(char const *s, char c[2])
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && (s[i] == c[0] || s[i] == c[1]))
		i++;
	while (s[i])
	{
		if (s[i] == c[0] || s[i] == c[1])
		{
			nb_strs++;
			while (s[i] && (s[i] == c[0] || s[i] == c[1]))
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c[0] || s[i - 1] != c[1])
		nb_strs++;
	return (nb_strs);
}

static void	next_string2(char **next_str, \
			unsigned int *next_str_len, char c[2])
{
	unsigned int	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = -1;
	while (**next_str && (**next_str == c[0] || **next_str == c[1]))
		(*next_str)++;
	while ((*next_str)[++i])
	{
		if ((*next_str)[i] == c[0] || (*next_str)[i] == c[1])
			return ;
		(*next_str_len)++;
	}
}

char	**ft_split2(char const *s, char c[2])
{
	char			**split;
	char			*next;
	unsigned int	ln_next;
	unsigned int	nb_strs;
	unsigned int	i;

	if (!s)
		return (NULL);
	nb_strs = get_strings2(s, c);
	split = (char **)malloc(sizeof(char *) * (nb_strs + 1));
	if (!split)
		return (NULL);
	i = -1;
	next = (char *)s;
	ln_next = 0;
	while (++i < nb_strs)
	{
		next_string2(&next, &ln_next, c);
		split[i] = (char *)malloc(sizeof(char) * (ln_next + 1));
		if (!split[i])
			return (error_free2(split));
		ft_strlcpy(split[i], next, ln_next + 1);
	}
	split[i] = NULL;
	return (split);
}