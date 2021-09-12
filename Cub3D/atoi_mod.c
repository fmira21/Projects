/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:19:10 by fmira             #+#    #+#             */
/*   Updated: 2021/04/03 16:27:09 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	strlen_int(const char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (ft_isdigit(str[i]))
	{
		count++;
		i++;
	}
	return (count);
}

int			ft_atoi_res(const char *str)
{
	long int	n;
	int			i;

	n = 0;
	i = 0;
	if (strlen_int(str) > 4)
		return (10000);
	while (str[i] == ' ')
		i++;
	while (*str)
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i++] - '0');
		else
			break ;
	}
	return ((int)(n));
}

int			ft_atoi_col(const char *str)
{
	long int	n;
	int			i;

	n = 0;
	i = 0;
	if (strlen_int(str) > 3)
		return (-1);
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i++] - '0');
		else
			break ;
	}
	if (n < 0 || n > 255)
		return (-1);
	return ((int)(n));
}
