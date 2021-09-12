/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:46:42 by fmira             #+#    #+#             */
/*   Updated: 2020/11/08 19:45:17 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	chr;
	char	*ptr;
	int		i;

	chr = (char)c;
	ptr = (char *)s;
	i = 0;
	while (ptr[i] != chr)
	{
		if (ptr[i] == '\0')
			return (NULL);
		i++;
	}
	return (&ptr[i]);
}
