/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 22:10:53 by fmira             #+#    #+#             */
/*   Updated: 2021/03/28 16:43:11 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			define_txfour(t_general *g)
{
	g->text.out_img = g->text.t4_img;
	g->text.out_raw = g->text.t4_raw;
	g->text.out_height = g->text.t4_height;
	g->text.out_width = g->text.t4_width;
	g->text.out_bpp = g->text.t4_bpp;
	g->text.out_en = g->text.t4_en;
	g->text.out_linel = g->text.t4_linel;
}

void			calc_tx(t_general *g)
{
	if (g->rtools.side == 0 && g->rtools.raydir_x > 0)
		define_txtwo(g);
	if (g->rtools.side == 1 && g->rtools.raydir_y < 0)
		define_txthree(g);
	if (g->rtools.side == 0 && g->rtools.raydir_x < 0)
		define_txfour(g);
}

void			draw_texture(t_general *g, int x)
{
	int y;
	int color;

	g->rtools.wall_x -= floor((g->rtools.wall_x));
	g->rtools.tex_x = (int)(g->rtools.wall_x * (double)g->text.out_width);
	if (g->rtools.side == 0 && g->rtools.raydir_x > 0)
		g->rtools.tex_x = g->text.out_width - g->rtools.tex_x - 1;
	if (g->rtools.side == 1 && g->rtools.raydir_y < 0)
		g->rtools.tex_x = g->text.out_width - g->rtools.tex_x - 1;
	g->rtools.step = 1.0 * g->text.out_height / g->rtools.lheight;
	g->rtools.tex_pos = (g->rtools.draw_start - g->res.height / \
	2 + g->rtools.lheight / 2) * g->rtools.step;
	y = g->rtools.draw_start;
	while (y < g->rtools.draw_end)
	{
		g->rtools.tex_y = (int)g->rtools.tex_pos \
		& (g->text.out_height - 1);
		g->rtools.pos = (g->rtools.tex_y * g->text.out_linel \
		+ g->rtools.tex_x * (g->text.out_bpp / 8));
		g->rtools.tex_pos += g->rtools.step;
		color = *(unsigned int *)(g->text.out_raw + g->rtools.pos);
		pixel_put(g, x, y, color);
		y++;
	}
}

void			calc_dsde(t_general *g)
{
	g->rtools.lheight = (int)(g->res.height / g->rtools.pwd);
	g->rtools.draw_start = -g->rtools.lheight / 2 + g->res.height / 2;
	if (g->rtools.draw_start < 0)
		g->rtools.draw_start = 0;
	g->rtools.draw_end = g->rtools.lheight / 2 + g->res.height / 2;
	if (g->rtools.draw_end >= g->res.height)
		g->rtools.draw_end = g->res.height;
}

void			cast_rays(t_general *g)
{
	char		**map;
	int			x;

	map = g->map.map_all;
	x = 0;
	while (x <= g->res.width)
	{
		init_rc(g, x);
		calc_deltadist(g);
		calc_step_sided(g);
		g->rtools.r_hit = 0;
		calc_mapside(g, map);
		calc_pwd(g);
		calc_tx(g);
		calc_dsde(g);
		if (g->rtools.side == 0)
			g->rtools.wall_x = g->plr.pos_y + g->rtools.pwd \
			* g->rtools.raydir_y;
		else
			g->rtools.wall_x = g->plr.pos_x + \
			g->rtools.pwd * g->rtools.raydir_x;
		draw_texture(g, x);
		draw_flceil(g, x, g->rtools.draw_start, g->rtools.draw_end);
		x++;
	}
}
