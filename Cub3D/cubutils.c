/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:31:51 by fmira             #+#    #+#             */
/*   Updated: 2021/04/01 19:39:10 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			close_all(t_general *g)
{
	int i;

	i = 0;
	if (g->config)
	{
		while (g->config[i])
		{
			free(g->config[i]);
			i++;
		}
		free(g->config);
	}
	g = NULL;
	exit(EXIT_SUCCESS);
}

void		puterror(char *msg, t_general *g)
{
	write(2, msg, ft_strlen(msg));
	close_all(g);
	exit(EXIT_SUCCESS);
}

void		puterror_nomlc(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_SUCCESS);
}

void		exc_entry(char *str, t_general *g, char *message)
{
	while (ft_isdigit(*str))
		str++;
	ignore_spaces(str);
	if (*str)
		puterror(message, g);
}

int			collision(char next, t_general *g)
{
	(void)g;
	if (next == '0' || next == '2' || next == 'N' \
	|| next == 'S' || next == 'E' || next == 'W')
		return (0);
	if (g->map.map_all[(int)g->plr.pos_x][(int)g->plr.pos_y] == '1' || !next)
		return (1);
	return (1);
}
