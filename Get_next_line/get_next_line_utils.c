/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:26:43 by fmira             #+#    #+#             */
/*   Updated: 2020/11/16 19:52:55 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
  size_t num;

  if(!s)
    return(0);
  num = 0;
  while (s[num] != '\0')
  {
    num++;
  }
  return (num);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*destination;
	size_t			i;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;

	if (src == dst)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
		{
			destination[i] = source[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dst);
}

char *strjoin_mod(char const *s1, char const *s2)
{
    char *joinstr;
    unsigned int jlen;

    if (!s1 && !s2)
        return (0);
    jlen = ft_strlen(s1) + ft_strlen(s2);
    if(!(joinstr = malloc(sizeof(char) * (jlen + 1))))
        return (0);
    ft_memmove(joinstr, s1, ft_strlen(s1));
    ft_memmove(joinstr + ft_strlen(s1), s2, ft_strlen(s2));
    joinstr[jlen] = '\0';
    free((char*)s1);
    return (joinstr);
}

int     parse_nl(char *str)
{
    int i;

    if(!str)
        return(0);
    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}