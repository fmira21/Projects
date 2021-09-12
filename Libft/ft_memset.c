/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:50:40 by fmira             #+#    #+#             */
/*   Updated: 2020/10/31 19:55:20 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char smb;

	ptr = (unsigned char *)s;
	smb = (unsigned char)c;
	while (n--)
	{
		*ptr++ = smb;
	}
	return (s);
}
