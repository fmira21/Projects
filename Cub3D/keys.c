/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:02:29 by fmira             #+#    #+#             */
/*   Updated: 2021/04/03 17:05:14 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int keycode, t_general *g)
{
	if (keycode == 13)
		g->plr.m_fwd = 1;
	else if (keycode == 1)
		g->plr.m_bwd = 1;
	else if (keycode == 0)
		g->plr.m_lt = 1;
	else if (keycode == 2)
		g->plr.m_rt = 1;
	else if (keycode == 123)
		g->plr.r_rt = 1;
	else if (keycode == 124)
		g->plr.r_lt = 1;
	else if (keycode == 53)
		close_all(g);
	return (0);
}

int		key_release(int keycode, t_general *g)
{
	if (keycode == 13)
		g->plr.m_fwd = 0;
	else if (keycode == 1)
		g->plr.m_bwd = 0;
	else if (keycode == 0)
		g->plr.m_lt = 0;
	else if (keycode == 2)
		g->plr.m_rt = 0;
	else if (keycode == 123)
		g->plr.r_rt = 0;
	else if (keycode == 124)
		g->plr.r_lt = 0;
	return (0);
}
