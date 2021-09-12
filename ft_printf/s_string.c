/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:08:30 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:08:32 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		put_str(char *str, t_flags flags)
{
	int counter;

	counter = 0;
	if (flags.dot >= 0)
	{
		counter += add_width(flags.dot, ft_strlen(str), 0);
		counter += put_str_wprec(str, flags.dot);
	}
	else
	{
		counter += put_str_wprec(str, ft_strlen(str));
	}
	return (counter);
}

int				proc_string(char *str, t_flags flags)
{
	int counter;

	counter = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		counter += put_str(str, flags);
	if (flags.dot >= 0)
		counter += add_width(flags.width, flags.dot, 0);
	else
		counter += add_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		counter += put_str(str, flags);
	return (counter);
}
