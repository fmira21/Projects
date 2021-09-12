/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numerals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:58:51 by fmira             #+#    #+#             */
/*   Updated: 2021/03/28 17:51:39 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr++ = 0x00;
	}
}

void	sprite_checker(t_general *g)
{
	if (g->sprite)
		puterror(NOSPRITEF, g);
	else
		g->sprite = 1;
}

void	texture_checker_34(int num, t_general *g)
{
	if (num == 3)
	{
		if (g->tex3)
			puterror(WEMUL, g);
		else
			g->tex3 = 1;
	}
	if (num == 4)
	{
		if (g->tex4)
			puterror(EAMUL, g);
		else
			g->tex4 = 1;
	}
}

void	texture_checker_12(int num, t_general *g)
{
	if (num == 1)
	{
		if (g->tex1)
			puterror(NOMUL, g);
		else
			g->tex1 = 1;
	}
	if (num == 2)
	{
		if (g->tex2)
			puterror(SOMUL, g);
		else
			g->tex2 = 1;
	}
}
