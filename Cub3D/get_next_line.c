/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:48:51 by fmira             #+#    #+#             */
/*   Updated: 2021/04/03 16:56:52 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t		ft_strlen(const char *s)
{
	size_t		num;

	if (!s)
		return (0);
	num = 0;
	while (s[num] != '\0')
	{
		num++;
	}
	return (num);
}

char		*strjoin_gnl(char *s1, char *s2)
{
	int		i;
	char	*joined;

	if (!(joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	joined[i++] = s2[0];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

int			get_next_line(int fd, char **line)
{
	char		buf[2];
	int			i;

	i = 0;
	if (fd <= 0 || !line || read(0, NULL, 0) < 0)
		return (-1);
	if (!(*line = (char *)malloc(1)))
		return (-1);
	**line = '\0';
	while (read(fd, buf, 1) > 0)
	{
		buf[1] = '\0';
		if (buf[0] == '\n')
			return (1);
		if (!(*line = strjoin_gnl(*line, buf)))
			return (-1);
	}
	return (0);
}
