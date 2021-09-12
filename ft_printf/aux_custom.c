/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_custom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:04:19 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:04:23 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_str_wprec(char *str, int precision)
{
	int		counter;

	counter = 0;
	while (str[counter] && counter < precision)
	{
		ft_putchar(str[counter]);
		counter++;
	}
	return (counter);
}

int			add_width(int width, int minus, int iszero)
{
	int		counter;

	counter = 0;
	while (width - minus > 0)
	{
		if (iszero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		counter++;
	}
	return (counter);
}
