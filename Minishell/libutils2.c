#include "includes/minishell.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str1;
	char	*str2;
	char	*dst;
	size_t	i;
	size_t	size_dst;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	dst = NULL;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_dst = ft_strlen(s1) + ft_strlen(s2);
	dst = malloc(sizeof(char) * (size_dst + 1));
	if (dst == NULL)
	{
		perror("Error: Can't allocate memory\n");
		exit(0);
	}
	while (*str1 != '\0')
		dst[i++] = *str1++;
	while (*str2 != '\0')
		dst[i++] = *str2++;
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*ptr_str1;
	unsigned char	*ptr_str2;

	ptr_str1 = (unsigned char *) str1;
	ptr_str2 = (unsigned char *) str2;
	if (!ptr_str1 || !ptr_str2)
		return (2);
	while (*ptr_str1 && *ptr_str2)
	{
		if (*ptr_str1 != *ptr_str2)
		{
			if (*ptr_str1 - *ptr_str2 > 0)
				return (1);
			else
				return (-1);
		}
		ptr_str1++;
		ptr_str2++;
	}
	if (*ptr_str1 == '\0' && *ptr_str2 == '\0')
		return (0);
	if (*ptr_str1 != *ptr_str2)
		if (*ptr_str1 - *ptr_str2 > 0)
			return (1);
	return (-1);
}

char	*ft_strchr(const char *s, int c)
{
	char	*src;

	src = (char *)s;
	while (*src != '\0')
	{
		if (*src == (char)c)
			return (src);
		src++;
	}
	if (*src == (char)c && (char)c == '\0')
		return (src);
	return (NULL);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}