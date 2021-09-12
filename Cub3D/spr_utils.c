/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:12:24 by fmira             #+#    #+#             */
/*   Updated: 2021/03/26 23:22:17 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			init_drs(t_general *g, int y)
{
	g->text.sprites_tr.d = y * 256 - g->res.height * 128 \
	+ g->text.sprites_tr.sprite_h * 128;
	g->text.sprites_tr.tex_y = ((g->text.sprites_tr.d * g->text.spr_height) \
	/ g->text.sprites_tr.sprite_h) / 256;
	if (g->text.sprites_tr.tex_y < 0)
		g->text.sprites_tr.tex_y = 0;
	g->text.sprites_tr.pos = (g->text.sprites_tr.tex_y * g->text.spr_linel \
	+ g->text.sprites_tr.tex_x * (g->text.spr_bpp / 8));
}

int				fill_sprstr(t_general *g, char **map, t_sprites *spr, int i)
{
	while (map[g->text.sprites_tr.x][g->text.sprites_tr.y])
	{
		if (map[g->text.sprites_tr.x][g->text.sprites_tr.y] == '2' \
		&& map[g->text.sprites_tr.x][g->text.sprites_tr.y + 1] \
		&& map[g->text.sprites_tr.x][g->text.sprites_tr.y - 1] != ' ')
		{
			spr[i].x = g->text.sprites_tr.x;
			spr[i++].y = g->text.sprites_tr.y;
		}
		else if (map[g->text.sprites_tr.x][g->text.sprites_tr.y] == '2' \
		&& ((!map[g->text.sprites_tr.x][g->text.sprites_tr.y + 1] \
		|| !map[g->text.sprites_tr.x][g->text.sprites_tr.y - 1]) \
		|| (map[g->text.sprites_tr.x][g->text.sprites_tr.y + 1] == ' ' \
		|| map[g->text.sprites_tr.x][g->text.sprites_tr.y - 1] == ' ')))
			puterror(SPRVOID, g);
		g->text.sprites_tr.y++;
	}
	return (i);
}
