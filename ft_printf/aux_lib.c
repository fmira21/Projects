/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:04:44 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:04:46 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

size_t		ft_strlen(const char *s)
{
	size_t num;

	num = 0;
	while (s[num] != '\0')
	{
		num++;
	}
	return (num);
}

char		*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc((ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int			ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
