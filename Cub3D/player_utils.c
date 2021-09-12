/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:33:02 by fmira             #+#    #+#             */
/*   Updated: 2021/03/28 17:52:47 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_void(t_general *g)
{
	int			x;
	int			y;
	char		**map;

	x = g->plr.pos_x;
	y = g->plr.pos_y;
	map = g->map.map_all;
	if (map[x][y - 1] == ' ' || !map[x][y - 1] || !map[x][y + 1])
		puterror(VOID, g);
}

void		set_player(t_general *g, int x, int y)
{
	g->plr.pos_x = x;
	g->plr.pos_y = y;
	g->plr.m_fwd = 0;
	g->plr.m_bwd = 0;
	g->plr.m_lt = 0;
	g->plr.m_rt = 0;
	g->plr.r_rt = 0;
	g->plr.r_lt = 0;
}

void		find_player(t_general *g)
{
	int	i;
	int	j;

	i = 0;
	g->player = 0;
	while (g->map.map_all[i])
	{
		j = 0;
		while (g->map.map_all[i][j])
		{
			if (g->map.map_all[i][j] == 'N' || g->map.map_all[i][j] == 'S' \
			|| g->map.map_all[i][j] == 'E' || g->map.map_all[i][j] == 'W')
			{
				if (g->player == 1)
					puterror(MULPLR, g);
				g->player = 1;
				set_player(g, i, j);
				check_dir(g, i, j);
			}
			j++;
		}
		i++;
	}
	if (g->player == 0)
		puterror(NOSPAWN, g);
}
