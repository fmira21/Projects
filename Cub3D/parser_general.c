/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_general.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:04:24 by fmira             #+#    #+#             */
/*   Updated: 2021/04/01 20:07:23 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	confverify(t_general *g)
{
	if (!(g->resolution))
		puterror(NORES, g);
	if (!(g->floor))
		puterror(NOFLOOR, g);
	if (!(g->ceiling))
		puterror(NOCEILING, g);
	if (!g->tex1)
		puterror(NOTEXNO, g);
	if (!g->tex2)
		puterror(NOTEXSO, g);
	if (!g->tex3)
		puterror(NOTEXWE, g);
	if (!g->tex4)
		puterror(NOTEXEA, g);
	if (!g->sprite)
		puterror(NOTEXSPR, g);
}

void	init_params(t_general *g)
{
	g->resolution = 0;
	g->floor = 0;
	g->ceiling = 0;
	g->tex1 = 0;
	g->tex2 = 0;
	g->tex3 = 0;
	g->tex4 = 0;
	g->sprite = 0;
	g->res.height = 0;
	g->res.width = 0;
	g->clr.floor_r = -1;
	g->clr.floor_g = -1;
	g->clr.floor_b = -1;
	g->clr.ceil_r = -1;
	g->clr.ceil_g = -1;
	g->clr.ceil_b = -1;
}

char	**gnl_config(char **lconfig, char **tmp, int fd)
{
	char	*s;
	int		i;
	int		j;
	int		readable;

	readable = 1;
	i = 1;
	while (readable)
	{
		readable = get_next_line(fd, &s);
		tmp = lconfig;
		j = 0;
		lconfig = malloc((i + 1) * sizeof(char *));
		if (tmp)
			while (tmp[j])
			{
				lconfig[j] = tmp[j];
				j++;
			}
		free(tmp);
		lconfig[j++] = s;
		lconfig[j] = 0;
		i++;
	}
	return (lconfig);
}

char	**parse_parameters(t_general *g, char **config)
{
	int i;
	int j;
	int map;

	i = 0;
	map = 0;
	while (config[i])
	{
		j = 0;
		while (config[i][j] == ' ')
			j++;
		if (!conf_crawler(config[i], g))
			return (&config[i]);
		i++;
	}
	puterror(NOMAPC, g);
	return (config);
}

int		parse_config(char *file, t_general *g)
{
	int		fd;
	char	**tmp;
	char	**lconfig;

	check_file(file);
	if ((fd = open(file, O_RDONLY)) < 0)
		puterror_nomlc(NOMLX);
	if (mlx_get_screen_size(g->win.mlx, &g->res.w_screen, &g->res.h_screen) < 0)
		puterror_nomlc(NOMLX);
	tmp = NULL;
	g->text.spr_count = 0;
	g->config = 0;
	g->config = gnl_config(g->config, tmp, fd);
	close(fd);
	init_params(g);
	lconfig = parse_parameters(g, g->config);
	confverify(g);
	parse_map(g, lconfig);
	if (g->text.spr_count)
		g->text.sprites = get_sprites(g);
	g->text.spr_hit = 0;
	return (1);
}
