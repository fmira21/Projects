/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:16:58 by fmira             #+#    #+#             */
/*   Updated: 2020/11/08 19:05:23 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int nbt;

	if (n < 0)
	{
		nbt = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
	{
		nbt = n;
	}
	if (nbt >= 10)
	{
		ft_putnbr_fd((nbt / 10), fd);
		ft_putnbr_fd((nbt % 10), fd);
	}
	else
	{
		ft_putchar_fd((nbt + '0'), fd);
	}
}
