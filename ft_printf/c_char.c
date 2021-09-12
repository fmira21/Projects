/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:04:53 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:04:56 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		proc_char(char c, t_flags flags)
{
	int counter;

	counter = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	counter = add_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (counter + 1);
}
