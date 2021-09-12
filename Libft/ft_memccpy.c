/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:14:05 by fmira             #+#    #+#             */
/*   Updated: 2020/10/31 23:05:15 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;
	unsigned char	chr;
	size_t			i;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		if (source[i] == chr)
		{
			i++;
			return (&destination[i]);
		}
		i++;
	}
	return (NULL);
}
