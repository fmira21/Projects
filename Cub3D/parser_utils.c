/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:16:21 by fmira             #+#    #+#             */
/*   Updated: 2021/04/03 17:08:36 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*ft_strnstr(const char *hayst, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;
	size_t	nlen;
	char	*hay;

	hay = (char *)hayst;
	nlen = ft_strlen(needle);
	if (!nlen)
		return (hay);
	if (ft_strlen(hayst) < nlen || len < nlen)
		return (NULL);
	i = 0;
	while (hay[i] && i <= len - nlen)
	{
		j = 0;
		while (needle[j] && needle[j] == hay[i + j])
			j++;
		if (j == nlen)
			return (&hay[i]);
		i++;
	}
	return (NULL);
}

void		check_file(char *file)
{
	int fd;

	if ((fd = open(file, O_DIRECTORY)) > 0)
		puterror_nomlc(ISDIR);
	if (!ft_strnstr(file, ".cub", ft_strlen(file)))
		puterror_nomlc(INVFILE);
}

char		*ignore_spaces(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

void		check_colentries(char c, t_general *g)
{
	if (c < '0' || c > '9')
		puterror(INVCOL, g);
}

void		check_colors(int d, t_general *g)
{
	if (d == 1)
	{
		if (g->clr.ceil_r == -1 || \
		g->clr.ceil_g == -1 || g->clr.ceil_b == -1)
			puterror(FVAL, g);
	}
	if (d == 2)
	{
		if (g->clr.floor_r == -1 || \
		g->clr.floor_g == -1 || g->clr.floor_b == -1)
			puterror(FVAL, g);
	}
}
