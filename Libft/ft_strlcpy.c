/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:25:16 by fmira             #+#    #+#             */
/*   Updated: 2020/11/07 20:49:23 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*destination;
	const char	*source;
	size_t		n;

	if (!dst || !src)
		return (0);
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
