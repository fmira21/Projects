/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:41:44 by fmira             #+#    #+#             */
/*   Updated: 2020/11/09 21:38:58 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_inset(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
//
char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start_trim;
	int		end_trim;
	int		trindex;

	if (!s1 || !set)
		return (NULL);
	start_trim = 0;
	trindex = 0;
	end_trim = ft_strlen(s1);
	while (s1[start_trim] && ft_inset(s1[start_trim], set) == 1)
		start_trim++;
	while (end_trim > start_trim && ft_inset(s1[end_trim - 1], set) == 1)
		end_trim--;
	if (!(trim = (char *)malloc(sizeof(char) * (end_trim - start_trim + 1))))
		return (NULL);
	while (start_trim < end_trim)
	{
		trim[trindex] = s1[start_trim];
		trindex++;
		start_trim++;
	}
	trim[trindex] = '\0';
	return (trim);
}
