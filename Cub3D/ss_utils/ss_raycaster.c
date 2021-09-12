/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 22:10:53 by fmira             #+#    #+#             */
/*   Updated: 2021/04/01 12:01:37 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			bmp_calc_deltadist(t_general *g)
{
	if (g->rtools.raydir_y == 0)
		g->rtools.deltadist_x = 0;
	else
	{
		if (g->rtools.raydir_x == 0)
			g->rtools.deltadist_x = 1;
		else
			g->rtools.deltadist_x = fabs(1 / g->rtools.raydir_x);
	}
	if (g->rtools.raydir_x == 0)
		g->rtools.deltadist_y = 0;
	else
	{
		if (g->rtools.raydir_y == 0)
			g->rtools.deltadist_y = 1;
		else
			g->rtools.deltadist_y = fabs(1 / g->rtools.raydir_y);
	}
}

void			bmp_draw_texture(t_general *g, int x)
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
	g->rtools.tex_pos = (g->rtools.draw_start - g->bmp.h_bmp / \
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
		bmp_pixel_put(g, x, y, color);
		y++;
	}
}

void			bmp_calc_dsde(t_general *g)
{
	g->rtools.lheight = (int)(g->bmp.h_bmp / g->rtools.pwd);
	g->rtools.draw_start = -g->rtools.lheight / 2 + g->bmp.h_bmp / 2;
	if (g->rtools.draw_start < 0)
		g->rtools.draw_start = 0;
	g->rtools.draw_end = g->rtools.lheight / 2 + g->bmp.h_bmp / 2;
	if (g->rtools.draw_end >= g->bmp.h_bmp)
		g->rtools.draw_end = g->bmp.h_bmp;
	g->rtools.r_hit = 0;
}

void			bmp_calc_tx(t_general *g)
{
	if (g->rtools.side == 0 && g->rtools.raydir_x > 0)
		define_txtwo(g);
	if (g->rtools.side == 1 && g->rtools.raydir_y < 0)
		define_txthree(g);
	if (g->rtools.side == 0 && g->rtools.raydir_x < 0)
		define_txfour(g);
}

void			bmp_cast_rays(t_general *g)
{
	char		**map;
	int			x;

	map = g->map.map_all;
	x = 0;
	while (x < g->bmp.w_bmp)
	{
		bmp_init_rc(g, x);
		bmp_calc_dsde(g);
		bmp_calc_deltadist(g);
		bmp_calc_step_sided(g);
		bmp_calc_mapside(g, map);
		bmp_calc_pwd(g);
		bmp_calc_tx(g);
		bmp_calc_dsde(g);
		if (g->rtools.side == 0)
			g->rtools.wall_x = g->plr.pos_y + g->rtools.pwd \
			* g->rtools.raydir_y;
		else
			g->rtools.wall_x = g->plr.pos_x + \
			g->rtools.pwd * g->rtools.raydir_x;
		bmp_draw_texture(g, x);
		bmp_draw_flceil(g, x, g->rtools.draw_start, g->rtools.draw_end);
		x++;
	}
}
