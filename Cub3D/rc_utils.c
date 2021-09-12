/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:44:22 by fmira             #+#    #+#             */
/*   Updated: 2021/03/26 22:57:16 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			pixel_put(t_general *g, int x, int y, int color)
{
	char	*dst;

	dst = g->win.addr + (y * g->win.line_l + x * (g->win.bpp / 8));
	*(unsigned int*)dst = color;
}

int				sum_rgb(int r, int g, int b)
{
	int		result;

	result = r;
	result = (result << 8) + g;
	result = (result << 8) + b;
	return (result);
}

void			draw_flceil(t_general *g, int x, int draw_start, int draw_end)
{
	int		y;
	char	*dst;

	y = -1;
	while (++y < g->res.height)
	{
		if (y < draw_start)
		{
			dst = g->win.addr + (y * g->win.line_l + x * (g->win.bpp / 8));
			*(unsigned int *)dst = sum_rgb(g->clr.ceil_r, \
			g->clr.ceil_g, g->clr.ceil_b);
		}
		else if (y > draw_end)
		{
			dst = g->win.addr + (y * g->win.line_l + x * (g->win.bpp / 8));
			*(unsigned int *)dst = sum_rgb(g->clr.floor_r, \
			g->clr.floor_g, g->clr.floor_b);
		}
	}
}

void			init_rc(t_general *g, int x)
{
	g->rtools.camera_x = 2 * x / (float)g->res.width - 1;
	g->rtools.raydir_x = g->plr.dir_x + g->plr.plane_x * g->rtools.camera_x;
	g->rtools.raydir_y = g->plr.dir_y + g->plr.plane_y * g->rtools.camera_x;
	g->rtools.map_x = (int)g->plr.pos_x;
	g->rtools.map_y = (int)g->plr.pos_y;
	g->text.out_img = g->text.t1_img;
	g->text.out_raw = g->text.t1_raw;
	g->text.out_height = g->text.t1_height;
	g->text.out_width = g->text.t1_width;
	g->text.out_bpp = g->text.t1_bpp;
	g->text.out_en = g->text.t1_en;
	g->text.out_linel = g->text.t1_linel;
	g->text.sprites_tr.zbuffer[x] = g->rtools.pwd;
}

void			calc_deltadist(t_general *g)
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
