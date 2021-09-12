/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:09:11 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:09:13 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*save_hex_sm_two(unsigned long hex, char *s, int i)
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

static char		*save_hex_sm(unsigned long ul)
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
	s = save_hex_sm_two(hex, s, i);
	return (s);
}

static char		*save_hex_bg_two(unsigned long hex, char *s, int i)
{
	s[i] = '\0';
	i--;
	while (hex != 0)
	{
		if ((hex % 16) < 10)
			s[i] = (hex % 16) + 48;
		else
			s[i] = (hex % 16) + 55;
		hex /= 16;
		i--;
	}
	return (s);
}

static char		*save_hex_bg(unsigned long ul)
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
	s = save_hex_bg_two(hex, s, i);
	return (s);
}

int				proc_hex(unsigned int ui, int capitals, t_flags flags)
{
	char	*hexa;
	int		counter;

	counter = 0;
	ui = (unsigned int)(4294967295 + 1 + ui);
	if (flags.dot == 0 && ui == 0)
	{
		counter += add_width(flags.width, 0, 0);
		return (counter);
	}
	if (capitals == 0)
		hexa = save_hex_sm((unsigned long)ui);
	else
		hexa = save_hex_bg((unsigned long)ui);
	counter += write_hex(hexa, flags);
	free(hexa);
	return (counter);
}
