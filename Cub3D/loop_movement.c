/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:28:50 by fmira             #+#    #+#             */
/*   Updated: 2021/04/01 15:02:40 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		movement_lr(t_general *g)
{
	if (g->plr.m_lt)
	{
		if (!collision(g->map.map_all[(int)(g->plr.pos_x - \
		g->plr.plane_x * MSPEED)][(int)(g->plr.pos_y)], g))
			g->plr.pos_x -= g->plr.plane_x * MSPEED;
		if (!collision(g->map.map_all[(int)(g->plr.pos_x)]\
		[(int)(g->plr.pos_y - g->plr.plane_y * MSPEED)], g))
			g->plr.pos_y -= g->plr.plane_y * MSPEED;
	}
	if (g->plr.m_rt)
	{
		if (!collision(g->map.map_all[(int)(g->plr.pos_x \
		+ g->plr.plane_x * MSPEED)][(int)(g->plr.pos_y)], g))
			g->plr.pos_x += g->plr.plane_x * MSPEED;
		if (!collision(g->map.map_all[(int)(g->plr.pos_x)]\
		[(int)(g->plr.pos_y + g->plr.plane_y * MSPEED)], g))
			g->plr.pos_y += g->plr.plane_y * MSPEED;
	}
	return (0);
}

int		movement_fb(t_general *g)
{
	if (g->plr.m_fwd)
	{
		if (!collision(g->map.map_all[(int)(g->plr.pos_x + \
		g->plr.dir_x * MSPEED)][(int)(g->plr.pos_y)], g))
			g->plr.pos_x += g->plr.dir_x * MSPEED;
		if (!collision(g->map.map_all[(int)(g->plr.pos_x)]\
		[(int)(g->plr.pos_y + g->plr.dir_y * MSPEED)], g))
			g->plr.pos_y += g->plr.dir_y * MSPEED;
	}
	if (g->plr.m_bwd)
	{
		if (!collision(g->map.map_all[(int)(g->plr.pos_x - \
		g->plr.dir_x * MSPEED)][(int)(g->plr.pos_y)], g))
			g->plr.pos_x -= g->plr.dir_x * MSPEED;
		if (!collision(g->map.map_all[(int)(g->plr.pos_x)]\
		[(int)(g->plr.pos_y - g->plr.dir_y * MSPEED)], g))
			g->plr.pos_y -= g->plr.dir_y * MSPEED;
	}
	return (0);
}

void	rotation_right(t_general *g)
{
	if (g->plr.r_rt)
	{
		g->rtools.old_dir_xr = g->plr.dir_x;
		g->plr.dir_x = (g->plr.dir_x * cos(RSPEED) \
		- g->plr.dir_y * sin(RSPEED));
		g->plr.dir_y = (g->rtools.old_dir_xr * sin(RSPEED) \
		+ g->plr.dir_y * cos(RSPEED));
		g->rtools.old_plane_xr = g->plr.plane_x;
		g->plr.plane_x = (g->plr.plane_x * cos(RSPEED) \
		- g->plr.plane_y * sin(RSPEED));
		g->plr.plane_y = (g->rtools.old_plane_xr * sin(RSPEED) \
		+ g->plr.plane_y * cos(RSPEED));
	}
}

void	rotation_left(t_general *g)
{
	if (g->plr.r_lt)
	{
		g->rtools.old_dir_xl = g->plr.dir_x;
		g->plr.dir_x = (g->plr.dir_x * cos(-RSPEED) \
		- g->plr.dir_y * sin(-RSPEED));
		g->plr.dir_y = (g->rtools.old_dir_xl * sin(-RSPEED) \
		+ g->plr.dir_y * cos(-RSPEED));
		g->rtools.old_plane_xl = g->plr.plane_x;
		g->plr.plane_x = (g->plr.plane_x * cos(-RSPEED) \
		- g->plr.plane_y * sin(-RSPEED));
		g->plr.plane_y = (g->rtools.old_plane_xl * sin(-RSPEED) \
		+ g->plr.plane_y * cos(RSPEED));
	}
}
