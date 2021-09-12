/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:48:49 by fmira             #+#    #+#             */
/*   Updated: 2020/11/08 19:48:22 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char			*joinstr;
	unsigned int	i;
	unsigned int	j;
	unsigned int	jlen;

	if (!s1 || !s2)
		return (NULL);
	jlen = ft_strlen(s1) + ft_strlen(s2);
	joinstr = malloc(sizeof(char) * (jlen + 1));
	if (!joinstr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joinstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joinstr[i++] = s2[j];
		j++;
	}
	joinstr[i] = '\0';
	return (joinstr);
}
