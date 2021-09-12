/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:05:04 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:05:07 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_int_two(char *d_i, int save_i, t_flags flags)
{
	int counter;

	counter = 0;
	if (save_i < 0 && flags.dot >= 0 && save_i > -2147483648)
		ft_putchar('-');
	if (flags.dot >= 0)
		counter += add_width(flags.dot - 1, ft_strlen(d_i) - 1, 1);
	counter += put_str_wprec(d_i, ft_strlen(d_i));
	return (counter);
}

static int	write_int(char *d_i, int save_i, t_flags flags)
{
	int counter;

	counter = 0;
	if (flags.minus == 1)
		counter += write_int_two(d_i, save_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		counter += add_width(flags.width, 0, 0);
	}
	else
		counter += add_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		counter += write_int_two(d_i, save_i, flags);
	return (counter);
}

int			proc_int(int i, t_flags flags)
{
	char	*str;
	int		buf;
	int		counter;

	buf = i;
	counter = 0;
	if (flags.dot == 0 && i == 0)
	{
		return (counter += add_width(flags.width, 0, 0));
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot < 0 && i > -2147483648)
			put_str_wprec("-", 1);
		if (i == -2147483648)
			counter--;
		i *= -1;
		flags.zero = 1;
		flags.width--;
		counter++;
	}
	str = ft_itoa(i);
	counter += write_int(str, buf, flags);
	free(str);
	return (counter);
}
