/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <fmira@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:17:15 by fmira             #+#    #+#             */
/*   Updated: 2020/11/08 20:37:22 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
