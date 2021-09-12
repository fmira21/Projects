/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:58:56 by fmira             #+#    #+#             */
/*   Updated: 2021/03/22 22:08:40 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dir_n(t_general *g)
{
	g->plr.dir_x = -1;
	g->plr.dir_y = 0;
	g->plr.plane_x = 0;
	g->plr.plane_y = 0.66;
}

void	dir_e(t_general *g)
{
	g->plr.dir_x = 0;
	g->plr.dir_y = 1;
	g->plr.plane_x = 0.66;
	g->plr.plane_y = 0;
}

void	dir_s(t_general *g)
{
	g->plr.dir_x = 1;
	g->plr.dir_y = 0;
	g->plr.plane_x = 0;
	g->plr.plane_y = -0.66;
}

void	dir_w(t_general *g)
{
	g->plr.dir_x = 0;
	g->plr.dir_y = -1;
	g->plr.plane_x = -0.66;
	g->plr.plane_y = 0;
}

void	check_dir(t_general *g, int i, int j)
{
	if (g->map.map_all[i][j] == 'N')
		dir_n(g);
	else if (g->map.map_all[i][j] == 'E')
		dir_e(g);
	else if (g->map.map_all[i][j] == 'S')
		dir_s(g);
	else if (g->map.map_all[i][j] == 'W')
		dir_w(g);
}
