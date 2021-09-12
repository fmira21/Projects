/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:09:07 by fmira             #+#    #+#             */
/*   Updated: 2021/03/26 23:21:51 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			put_sprites(t_general *g)
{
	int x;
	int y;
	int color;

	x = g->text.sprites_tr.sprite_dsx;
	while (x < g->text.sprites_tr.sprite_dex)
	{
		g->text.sprites_tr.tex_x = (int)((x - (-(g->text.sprites_tr.sprite_w)\
		/ 2 + g->text.sprites_tr.spritescreen_x)) * g->text.spr_width \
		/ g->text.sprites_tr.sprite_w);
		y = g->text.sprites_tr.sprite_dsy;
		if (g->text.sprites_tr.transform_y > 0 && x >= 0 && x < g->res.width \
		&& g->text.sprites_tr.transform_y < g->text.sprites_tr.zbuffer[x])
			while (y < g->text.sprites_tr.sprite_dey)
			{
				init_drs(g, y);
				color = *(unsigned int *)(g->text.spr_raw + \
				g->text.sprites_tr.pos);
				if ((color & 0x00FFFFFF) != 0)
					pixel_put(g, x, y, color);
				y++;
			}
		x++;
	}
}

void			get_sprdimensions(t_general *g)
{
	g->text.sprites_tr.sprite_h = abs((int)(g->res.height \
	/ (g->text.sprites_tr.transform_y)));
	g->text.sprites_tr.sprite_dsy = \
	-(g->text.sprites_tr.sprite_h) / 2 + g->res.height / 2;
	if (g->text.sprites_tr.sprite_dsy < 0)
		g->text.sprites_tr.sprite_dsy = 0;
	g->text.sprites_tr.sprite_dey = \
	g->text.sprites_tr.sprite_h / 2 + g->res.height / 2;
	if (g->text.sprites_tr.sprite_dey >= g->res.height)
		g->text.sprites_tr.sprite_dey = g->res.height;
	g->text.sprites_tr.sprite_w = \
	abs((int)(g->res.height / (g->text.sprites_tr.transform_y)));
	g->text.sprites_tr.sprite_dsx = \
	-(g->text.sprites_tr.sprite_w) / 2 + g->text.sprites_tr.spritescreen_x;
	if (g->text.sprites_tr.sprite_dsx < 0)
		g->text.sprites_tr.sprite_dsx = 0;
	g->text.sprites_tr.sprite_dex = \
	g->text.sprites_tr.sprite_w / 2 + g->text.sprites_tr.spritescreen_x;
	if (g->text.sprites_tr.sprite_dex >= g->res.width)
		g->text.sprites_tr.sprite_dex = g->res.width;
}

void			sort_sprites(t_general *g)
{
	double		distance[g->text.spr_count];
	int			tmp;
	int			dst_tmp;
	int			i;

	i = -1;
	while (++i < g->text.spr_count)
	{
		distance[i] = ((g->plr.pos_x - g->text.sprites[i].x) \
		* (g->plr.pos_x - g->text.sprites[i].x) + (g->plr.pos_y \
		- g->text.sprites[i].y) * (g->plr.pos_y - g->text.sprites[i].y));
		g->text.spr_order[i] = i;
	}
	i = -1;
	while (++i < g->text.spr_count - 1)
		if (distance[i] < distance[i + 1])
		{
			dst_tmp = distance[i];
			distance[i] = distance[i + 1];
			distance[i + 1] = dst_tmp;
			tmp = g->text.spr_order[i];
			g->text.spr_order[i] = g->text.spr_order[i + 1];
			g->text.spr_order[i + 1] = tmp;
			i = -1;
		}
}

void			draw_sprites(t_general *g)
{
	int			i;
	t_sprites	sprite_ptr;

	sort_sprites(g);
	i = 0;
	while (i < g->text.spr_count)
	{
		sprite_ptr = g->text.sprites[g->text.spr_order[i++]];
		g->text.sprites_tr.sprite_x = (sprite_ptr.x + 0.5) - g->plr.pos_x;
		g->text.sprites_tr.sprite_y = (sprite_ptr.y + 0.5) - g->plr.pos_y;
		g->text.sprites_tr.invdet = \
		1.0 / (g->plr.plane_x * g->plr.dir_y - g->plr.dir_x * g->plr.plane_y);
		g->text.sprites_tr.transform_x = g->text.sprites_tr.invdet * \
		(g->plr.dir_y * g->text.sprites_tr.sprite_x - g->plr.dir_x * \
		g->text.sprites_tr.sprite_y);
		g->text.sprites_tr.transform_y = \
		g->text.sprites_tr.invdet * (-(g->plr.plane_y) * \
		g->text.sprites_tr.sprite_x + g->plr.plane_x * \
		g->text.sprites_tr.sprite_y);
		g->text.sprites_tr.spritescreen_x = \
		(int)((g->res.width / 2) * (1 + g->text.sprites_tr.transform_x \
		/ g->text.sprites_tr.transform_y));
		get_sprdimensions(g);
		put_sprites(g);
	}
}

t_sprites		*get_sprites(t_general *g)
{
	t_sprites	*spr_arr;
	char		**map;
	int			i;

	map = g->map.map_all;
	spr_arr = (malloc(g->text.spr_count * sizeof(t_sprites)));
	g->text.spr_order = (malloc(g->text.spr_count * sizeof(int)));
	g->text.sprites_tr.x = 0;
	i = 0;
	while (map[g->text.sprites_tr.x])
	{
		g->text.sprites_tr.y = 0;
		i = fill_sprstr(g, map, spr_arr, i);
		g->text.sprites_tr.x++;
	}
	return (spr_arr);
}
