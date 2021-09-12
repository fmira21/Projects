/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:07:58 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:08:02 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int			is_flag(int c)
{
	return ((c == '-') || (c == '0') || (c == '.') || (c == '*') || (c == ' '));
}

t_flags		init_flags(void)
{
	t_flags		flags;

	flags.type = 0;
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.star = 0;
	return (flags);
}

int			parse_flag(const char *str, int i, t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !is_type(str[i]) && !is_flag(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = flag_dot(str, i, flags, args);
		if (str[i] == '-')
			*flags = flag_minus(*flags);
		if (str[i] == '*')
			*flags = flag_width(args, *flags);
		if (str[i] == ' ')
			ft_putchar(' ');
		if (ft_isdigit(str[i]))
			*flags = flag_digit(str[i], *flags);
		if (is_type(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int			parse_input(const char *str, va_list args)
{
	t_flags		flags;
	int			i;
	int			counter;

	i = 0;
	counter = 0;
	while (1)
	{
		flags = init_flags();
		if (!str[i])
			break ;
		else if (str[i] == '%' && str[i + 1])
		{
			i = parse_flag(str, ++i, &flags, args);
			if (is_type(str[i]))
				counter += processor((char)flags.type, flags, args);
			else if (str[i])
				counter += ft_putchar(str[i]);
		}
		else if (str[i] != '%')
			counter += ft_putchar(str[i]);
		i++;
	}
	return (counter);
}
