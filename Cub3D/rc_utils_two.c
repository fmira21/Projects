/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:58:35 by fmira             #+#    #+#             */
/*   Updated: 2021/03/26 23:11:02 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			calc_step_sided(t_general *g)
{
	if (g->rtools.raydir_x < 0)
	{
		g->rtools.step_x = -1;
		g->rtools.sidedist_x = (g->plr.pos_x - g->rtools.map_x) \
		* g->rtools.deltadist_x;
	}
	else
	{
		g->rtools.step_x = 1;
		g->rtools.sidedist_x = (g->rtools.map_x + 1.0 \
		- g->plr.pos_x) * g->rtools.deltadist_x;
	}
	if (g->rtools.raydir_y < 0)
	{
		g->rtools.step_y = -1;
		g->rtools.sidedist_y = (g->plr.pos_y - \
		g->rtools.map_y) * g->rtools.deltadist_y;
	}
	else
	{
		g->rtools.step_y = 1;
		g->rtools.sidedist_y = (g->rtools.map_y + \
		1.0 - g->plr.pos_y) * g->rtools.deltadist_y;
	}
}

void			calc_mapside(t_general *g, char **map)
{
	while (g->rtools.r_hit == 0)
	{
		if (g->rtools.sidedist_x < g->rtools.sidedist_y)
		{
			g->rtools.sidedist_x += g->rtools.deltadist_x;
			g->rtools.map_x += g->rtools.step_x;
			g->rtools.side = 0;
		}
		else
		{
			g->rtools.sidedist_y += g->rtools.deltadist_y;
			g->rtools.map_y += g->rtools.step_y;
			g->rtools.side = 1;
		}
		if (map[g->rtools.map_x][g->rtools.map_y] == '1' || \
		!map[g->rtools.map_x][g->rtools.map_y])
			g->rtools.r_hit = 1;
		if (map[g->rtools.map_x][g->rtools.map_y] == '2')
			g->text.spr_hit = 1;
	}
}

void			calc_pwd(t_general *g)
{
	if (g->rtools.side == 0)
		g->rtools.pwd = (g->rtools.map_x - g->plr.pos_x + \
		(1 - g->rtools.step_x) / 2) / g->rtools.raydir_x;
	else
		g->rtools.pwd = (g->rtools.map_y - g->plr.pos_y + \
		(1 - g->rtools.step_y) / 2) / g->rtools.raydir_y;
}

void			define_txtwo(t_general *g)
{
	g->text.out_img = g->text.t2_img;
	g->text.out_raw = g->text.t2_raw;
	g->text.out_height = g->text.t2_height;
	g->text.out_width = g->text.t2_width;
	g->text.out_bpp = g->text.t2_bpp;
	g->text.out_en = g->text.t2_en;
	g->text.out_linel = g->text.t2_linel;
}

void			define_txthree(t_general *g)
{
	g->text.out_img = g->text.t3_img;
	g->text.out_raw = g->text.t3_raw;
	g->text.out_height = g->text.t3_height;
	g->text.out_width = g->text.t3_width;
	g->text.out_bpp = g->text.t3_bpp;
	g->text.out_en = g->text.t3_en;
	g->text.out_linel = g->text.t3_linel;
}
