/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:08:20 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:08:22 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		processor(int c, t_flags flags, va_list args)
{
	int counter;

	counter = 0;
	if (c == 'c')
		counter += proc_char(va_arg(args, int), flags);
	else if (c == 's')
		counter += proc_string(va_arg(args, char *), flags);
	else if (c == 'p')
		counter += proc_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		counter += proc_int(va_arg(args, int), flags);
	else if (c == 'u')
		counter += proc_uint((unsigned int)va_arg(args, unsigned int),
		flags);
	else if (c == 'x')
		counter += proc_hex(va_arg(args, unsigned int), 0, flags);
	else if (c == 'X')
		counter += proc_hex(va_arg(args, unsigned int), 1, flags);
	else if (c == '%')
		counter += proc_percent(flags);
	return (counter);
}
