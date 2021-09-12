/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:08:11 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:08:14 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		proc_percent(t_flags flags)
{
	int counter;

	counter = 0;
	if (flags.minus == 1)
		counter += put_str_wprec("%", 1);
	counter += add_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		counter += put_str_wprec("%", 1);
	return (counter);
}
