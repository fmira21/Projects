#include "includes/minishell.h"

static char	*ft_mem(char const *str, char c)
{
	size_t	i;
	char	*w;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	w = (char *)malloc(sizeof(char) * (i + 1));
	if (!w)
		return (NULL);
	ft_strlcpy(w, str, i + 1);
	return (w);
}

static char	*ft_trap(char const *s, char c, size_t i)
{
	size_t	wc;
	char	*str;

	str = (char *)s;
	wc = 0;
	while (*str != '\0')
	{
		while (*str == c && *str != '\0')
			str++;
		if (*str != c && *str != '\0')
		{
			wc++;
			if (wc == i && *str != '\0')
				return (ft_mem(str, c));
			while (*(str + 1) != c && *(str + 1) != '\0')
				str++;
		}
		if (*str == '\0')
			break ;
		str++;
	}
	return (NULL);
}

static size_t	ft_wc(char const *s, char c)
{
	size_t	wc;
	char	*str;

	str = (char *)s;
	wc = 0;
	while (*str != '\0')
	{
		while (*str == c && *str != '\0')
			str++;
		if (*str != c && *str != '\0')
		{
			wc++;
			while (*(str + 1) != c && *(str + 1) != '\0')
				str++;
		}
		if (*str == '\0')
			break ;
		str++;
	}
	return (wc);
}

void	free_dm(char *s, int i)
{
	while (i > 1)
	{
		free(s);
		i--;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	wc;
	char	**dm;

	i = 0;
	if (s == NULL)
		return (NULL);
	wc = ft_wc(s, c);
	dm = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!dm)
		return (NULL);
	while (++i < wc + 1)
	{
		dm[i - 1] = ft_trap(s, c, i);
		if (!dm)
			free_dm(dm[i - 1], i);
	}
	dm[wc] = NULL;
	return (dm);
}
