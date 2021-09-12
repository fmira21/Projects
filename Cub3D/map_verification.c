/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:24:54 by fmira             #+#    #+#             */
/*   Updated: 2021/03/22 21:49:38 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_entries(t_general *g)
{
	char		**map;
	int			i;
	int			j;

	map = g->map.map_all;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' &&\
			map[i][j] != '2' && map[i][j] != 'N' && map[i][j] != 'S' \
			&& map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != ' ')
				puterror(INVEN, g);
			if (map[i][j] == '2')
				g->text.spr_count += 1;
			j++;
		}
		i++;
	}
}

void	revert_map(t_general *g)
{
	char		**map;
	int			i;
	int			j;

	map = g->map.map_all;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				map[i][j] = '0';
			if (map[i][j] == 'D')
				map[i][j] = '2';
			j++;
		}
		i++;
	}
}

void	check_boundaries(t_general *g, int x, int y)
{
	char	**map;

	map = g->map.map_all;
	if (!map[x][y])
		puterror(INVMAP, g);
	if (map[x][y] == '1' || map[x][y] == 'C' || map[x][y] == 'D')
		return ;
	if (x == 0 || y == 0 || x == g->map.x_max - 1)
		puterror(INVMAP, g);
	if (map[x][y] == '0')
		map[x][y] = 'C';
	if (map[x][y] == '2')
		map[x][y] = 'D';
	if (map[x][y] == ' ')
		puterror(INVEN, g);
	check_boundaries(g, x + 1, y);
	check_boundaries(g, x - 1, y);
	check_boundaries(g, x, y + 1);
	check_boundaries(g, x, y - 1);
	return ;
}
