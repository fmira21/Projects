/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:26:02 by fmira             #+#    #+#             */
/*   Updated: 2020/11/08 19:50:03 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	siz;

	i = 0;
	siz = ft_strlen(dst);
	if (dstsize <= siz)
		return (dstsize + ft_strlen(src));
	while (src[i] && siz + i < (dstsize - 1))
	{
		dst[i + siz] = src[i];
		i++;
	}
	dst[i + siz] = '\0';
	return (ft_strlen(src) + siz);
}
