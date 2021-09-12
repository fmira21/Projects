/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:53:32 by fmira             #+#    #+#             */
/*   Updated: 2021/03/28 17:20:51 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_x(char **lconfig, t_general *g)
{
	int i;
	int j;

	i = 0;
	while (lconfig[i])
	{
		j = 0;
		while (lconfig[i][j] == ' ')
			j++;
		if (!lconfig[i][j])
			puterror(EMLINE, g);
		i++;
	}
	return (i);
}

int		get_y(char **lconfig)
{
	int i;
	int j;
	int length;
	int result;

	i = 0;
	j = 0;
	result = 0;
	while (lconfig[i])
	{
		length = 0;
		j = 0;
		while (lconfig[i][j])
		{
			if (lconfig[i][j] != ' ')
				length++;
			j++;
		}
		if (length > result)
			result = length;
		i++;
	}
	return (result);
}

void	parse_map(t_general *g, char **lconfig)
{
	g->map.x_max = get_x(lconfig, g);
	g->map.y_max = get_y(lconfig);
	g->map.map_all = lconfig;
	find_player(g);
	check_void(g);
	check_entries(g);
	check_boundaries(g, g->plr.pos_x, g->plr.pos_y);
	revert_map(g);
}
