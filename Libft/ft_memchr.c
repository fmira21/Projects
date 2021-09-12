/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:17:48 by fmira             #+#    #+#             */
/*   Updated: 2020/11/08 18:20:29 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char smb;

	ptr = (unsigned char *)s;
	smb = (unsigned char)c;
	while (n--)
	{
		if (*ptr == smb)
		{
			return (ptr);
		}
		ptr++;
	}
	return (NULL);
}
