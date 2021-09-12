/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:08:52 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:08:53 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long		ft_order(long n)
{
	int	num;

	num = 1;
	if (n < 0)
	{
		n *= -1;
		num++;
	}
	while (n >= 10)
	{
		n /= 10;
		num++;
	}
	return (num);
}

char			*uitoa(unsigned int n)
{
	char	*str;
	int		order;
	int		i;
	long	lnum;

	lnum = (long)n;
	order = ft_order(lnum);
	str = (char *)malloc(order + 1);
	if (!str)
		return (NULL);
	if (lnum < 0)
		lnum *= -1;
	i = order;
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = (lnum % 10) + 48;
		lnum /= 10;
		i--;
	}
	if (n < 0)
		*str = '-';
	return (str);
}
