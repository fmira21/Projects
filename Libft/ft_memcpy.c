/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:37:22 by fmira             #+#    #+#             */
/*   Updated: 2020/10/31 22:46:44 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *source;
	unsigned char *destination;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	if (!dst && !src)
	{
		return (NULL);
	}
	while (n--)
	{
		*destination++ = *source++;
	}
	return (dst);
}
