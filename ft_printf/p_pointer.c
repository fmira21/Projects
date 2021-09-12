/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:07:37 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:07:39 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		write_pointer(char *pointer, t_flags flags)
{
	int			counter;

	counter = 0;
	counter += put_str_wprec("0x", 2);
	if (flags.dot >= 0)
	{
		counter += add_width(flags.dot, ft_strlen(pointer), 1);
		counter += put_str_wprec(pointer, flags.dot);
	}
	else
		counter += put_str_wprec(pointer, ft_strlen(pointer));
	return (counter);
}

static char		*save_addr_two(unsigned long hex, char *s, int i)
{
	s[i] = '\0';
	i--;
	while (hex != 0)
	{
		if ((hex % 16) < 10)
			s[i] = (hex % 16) + 48;
		else
			s[i] = (hex % 16) + 87;
		hex /= 16;
		i--;
	}
	return (s);
}

static char		*save_addr(unsigned long ul)
{
	unsigned long	hex;
	int				i;
	char			*s;

	i = 0;
	s = 0;
	hex = ul;
	if (ul == 0)
	{
		s = ft_strdup("0");
		return (s);
	}
	while (ul != 0)
	{
		ul /= 16;
		i++;
	}
	if (!(s = malloc((i + 1) * sizeof(char))))
		return (0);
	s = save_addr_two(hex, s, i);
	return (s);
}

int				proc_pointer(unsigned long ul, t_flags flags)
{
	char		*pointer;
	int			counter;

	counter = 0;
	if (ul == 0 && flags.dot == 0)
	{
		counter += put_str_wprec("0x", 2);
		return (counter += add_width(flags.width, 0, 1));
	}
	pointer = save_addr(ul);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		counter += write_pointer(pointer, flags);
	counter += add_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		counter += write_pointer(pointer, flags);
	free(pointer);
	return (counter);
}
