#include "includes/minishell.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	if (!s)
		return ;
	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ignore_quotes(str[i]))
			write(1, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	if (i != n)
		return (s1[i] - s2[i]);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*destination;
	const char	*source;
	size_t		n;

	destination = (char *)dst;
	source = (const char *)src;
	n = dstsize;
	if (n != 0)
	{
		while (--n != 0)
		{
			*destination++ = *source;
			if (*source++ == '\0')
				break ;
		}
	}
	if (n == 0 && dstsize != 0)
	{
		*destination = '\0';
	}
	return (ft_strlen(src));
}

