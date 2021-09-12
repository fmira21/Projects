/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <fmira@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:09:13 by fmira             #+#    #+#             */
/*   Updated: 2021/09/10 22:41:40 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
