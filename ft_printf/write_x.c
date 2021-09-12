/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:09:00 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:09:02 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		write_hex_two(char *hexa, t_flags flags)
{
	int			counter;

	counter = 0;
	if (flags.dot >= 0)
		counter += add_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
	counter += put_str_wprec(hexa, ft_strlen(hexa));
	return (counter);
}

int				write_hex(char *hexa, t_flags flags)
{
	int			counter;

	counter = 0;
	if (flags.minus == 1)
		counter += write_hex_two(hexa, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		counter += add_width(flags.width, 0, 0);
	}
	else
		counter += add_width(flags.width,
		ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		counter += write_hex_two(hexa, flags);
	return (counter);
}
