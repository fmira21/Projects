/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:09:07 by fmira             #+#    #+#             */
/*   Updated: 2021/03/30 21:40:23 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			bmp_put_sprites(t_general *g)
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
		if (g->text.sprites_tr.transform_y > 0 && x >= 0 && x < g->bmp.w_bmp \
		&& g->text.sprites_tr.transform_y < g->text.sprites_tr.zbuffer[x])
			while (y < g->text.sprites_tr.sprite_dey)
			{
				bmp_init_drs(g, y);
				color = *(unsigned int *)(g->text.spr_raw + \
				g->text.sprites_tr.pos);
				if ((color & 0x00FFFFFF) != 0)
					bmp_pixel_put(g, x, y, color);
				y++;
			}
		x++;
	}
}

void			bmp_get_sprdimensions(t_general *g)
{
	g->text.sprites_tr.sprite_h = abs((int)(g->bmp.h_bmp \
	/ (g->text.sprites_tr.transform_y)));
	g->text.sprites_tr.sprite_dsy = \
	-(g->text.sprites_tr.sprite_h) / 2 + g->bmp.h_bmp / 2;
	if (g->text.sprites_tr.sprite_dsy < 0)
		g->text.sprites_tr.sprite_dsy = 0;
	g->text.sprites_tr.sprite_dey = \
	g->text.sprites_tr.sprite_h / 2 + g->bmp.h_bmp / 2;
	if (g->text.sprites_tr.sprite_dey >= g->bmp.h_bmp)
		g->text.sprites_tr.sprite_dey = g->bmp.h_bmp;
	g->text.sprites_tr.sprite_w = \
	abs((int)(g->bmp.h_bmp / (g->text.sprites_tr.transform_y)));
	g->text.sprites_tr.sprite_dsx = \
	-(g->text.sprites_tr.sprite_w) / 2 + g->text.sprites_tr.spritescreen_x;
	if (g->text.sprites_tr.sprite_dsx < 0)
		g->text.sprites_tr.sprite_dsx = 0;
	g->text.sprites_tr.sprite_dex = \
	g->text.sprites_tr.sprite_w / 2 + g->text.sprites_tr.spritescreen_x;
	if (g->text.sprites_tr.sprite_dex >= g->bmp.w_bmp)
		g->text.sprites_tr.sprite_dex = g->bmp.w_bmp;
}

void			bmp_sort_sprites(t_general *g)
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

void			bmp_draw_sprites(t_general *g)
{
	int			i;
	t_sprites	sprite_ptr;

	bmp_sort_sprites(g);
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
		(int)((g->bmp.w_bmp / 2) * (1 + g->text.sprites_tr.transform_x \
		/ g->text.sprites_tr.transform_y));
		bmp_get_sprdimensions(g);
		bmp_put_sprites(g);
	}
}
