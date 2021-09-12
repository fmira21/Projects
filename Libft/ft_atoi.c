/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:35:20 by fmira             #+#    #+#             */
/*   Updated: 2020/11/09 18:59:57 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	size_t					i;
	unsigned long			res;
	unsigned long			limit;
	int						negflag;

	i = 0;
	res = 0;
	limit = 9223372036854775807 / 10;
	negflag = 1;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v' || \
			nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		negflag = -1;
	if (negflag == -1 || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (res > limit && negflag == 1)
			return (-1);
		if (res > limit && negflag == -1)
			return (0);
		res = (res * 10) + (nptr[i++] - '0');
	}
	return (res * negflag);
}
