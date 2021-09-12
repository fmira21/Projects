/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:12:01 by fmira             #+#    #+#             */
/*   Updated: 2020/11/08 18:16:41 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char			*ft_itoa(int n)
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
