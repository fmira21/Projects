/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:18:33 by fmira             #+#    #+#             */
/*   Updated: 2020/11/08 19:15:02 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_strnum(char const *s, char c)
{
	size_t	num;
	size_t	dword;

	num = 0;
	dword = 0;
	while (*s)
	{
		if (dword == 0 && *s != c && *s)
		{
			num++;
			dword = 1;
		}
		else if (dword == 1 && *s == c)
			dword = 0;
		s++;
	}
	return (num);
}

static size_t		ft_strlen_mod(char const *str, char c)
{
	size_t	strlen;

	strlen = 0;
	while (str[strlen] != c && str[strlen])
		strlen++;
	return (strlen);
}

static char			*ft_strdup_mod(char const *str, char c)
{
	char	*dupstr;
	size_t	i;

	dupstr = malloc(sizeof(char) * (ft_strlen_mod(str, c) + 1));
	if (!dupstr)
		return (NULL);
	i = 0;
	while (*str != c && *str)
	{
		dupstr[i] = *str;
		i++;
		str++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}

static void			ft_freesplit(char **split, size_t sz)
{
	size_t	i;

	i = 0;
	while (i < sz)
		free(split[i]);
	free(split);
}

char				**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * ft_strnum(s, c) + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		if (*s != c && *s)
		{
			if (!(split[i] = ft_strdup_mod(s, c)))
			{
				ft_freesplit(split, ft_strnum(s, c));
				return (NULL);
			}
			i++;
			s += ft_strlen_mod(s, c);
		}
	}
	split[i] = NULL;
	return (split);
}
