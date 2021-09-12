/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_uint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:08:44 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:08:45 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_uint_two(char *str, t_flags flags)
{
	int counter;

	counter = 0;
	if (flags.dot >= 0)
		counter += add_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	counter += put_str_wprec(str, ft_strlen(str));
	return (counter);
}

static int	write_uint(char *str, t_flags flags)
{
	int counter;

	counter = 0;
	if (flags.minus == 1)
		counter += write_uint_two(str, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		counter += add_width(flags.width, 0, 0);
	}
	else
		counter += add_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		counter += write_uint_two(str, flags);
	return (counter);
}

int			proc_uint(unsigned int ui, t_flags flags)
{
	char	*str;
	int		counter;

	counter = 0;
	ui = (unsigned int)(4294967295 + ui + 1);
	if (ui == 0 && flags.dot == 0)
	{
		counter += add_width(flags.width, 0, 0);
		return (counter);
	}
	str = uitoa(ui);
	counter += write_uint(str, flags);
	free(str);
	return (counter);
}
