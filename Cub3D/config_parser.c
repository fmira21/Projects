/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:06:15 by fmira             #+#    #+#             */
/*   Updated: 2021/04/03 17:01:37 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_res(char *line, t_general *g)
{
	if (g->resolution == 1)
		puterror(RMUL, g);
	line = ignore_spaces(line);
	g->res.width = ft_atoi_res(&(*line));
	g->bmp.w_bmp = g->res.width - 1;
	while (ft_isdigit(*line))
		line++;
	if (*line != ' ')
		puterror(WHEIGHT, g);
	line = ignore_spaces(line);
	g->res.height = ft_atoi_res(line);
	g->bmp.h_bmp = g->res.height - 1;
	exc_entry(line, g, EXCRES);
	if (g->res.height <= 0 || g->res.width <= 0)
		puterror(WRES, g);
	g->res.height = (g->res.height > g->res.h_screen ? \
	g->res.h_screen : g->res.height);
	g->res.width = (g->res.width > g->res.w_screen ? \
	g->res.w_screen - 1 : g->res.width - 1);
	g->resolution = 1;
}

void	make_floor(char *line, t_general *g)
{
	if (g->floor == 1)
		puterror(FMUL, g);
	line = ignore_spaces(line);
	check_colentries(*line, g);
	g->clr.floor_r = ft_atoi_col(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	if (*(line++) != ',')
		puterror(FCOL, g);
	line = ignore_spaces(line);
	check_colentries(*line, g);
	g->clr.floor_g = ft_atoi_col(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	if (*(line++) != ',')
		puterror(FCOL, g);
	line = ignore_spaces(line);
	check_colentries(*line, g);
	g->clr.floor_b = ft_atoi_col(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	if (*line)
		puterror(FVAL, g);
	check_colors(2, g);
	g->floor = 1;
}

void	make_ceiling(char *line, t_general *g)
{
	if (g->ceiling == 1)
		puterror(CMUL, g);
	line = ignore_spaces(line);
	check_colentries(*line, g);
	g->clr.ceil_r = ft_atoi_col(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	if (*(line++) != ',')
		puterror(CCOL, g);
	line = ignore_spaces(line);
	check_colentries(*line, g);
	g->clr.ceil_g = ft_atoi_col(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	if (*(line++) != ',')
		puterror(CCOL, g);
	line = ignore_spaces(line);
	check_colentries(*line, g);
	g->clr.ceil_b = ft_atoi_col(line);
	while (ft_isdigit(*line) || *line == ' ')
		line++;
	if (*line)
		puterror(CVAL, g);
	check_colors(1, g);
	g->ceiling = 1;
}

int		conf_crawler(char *line, t_general *g)
{
	line = ignore_spaces(line);
	if (*line == 'R' && *(line + 1) == ' ')
		make_res(line + 1, g);
	else if (*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
		make_tex1(line + 2, g);
	else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
		make_tex2(line + 2, g);
	else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
		make_tex3(line + 2, g);
	else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
		make_tex4(line + 2, g);
	else if (*line == 'S' && *(line + 1) == ' ')
		make_sprite(line + 1, g);
	else if (*line == 'F' && *(line + 1) == ' ')
		make_floor(line + 1, g);
	else if (*line == 'C' && *(line + 1) == ' ')
		make_ceiling(line + 1, g);
	else if (*line == '1' || *line == '0' || *line == '2')
		return (0);
	else if (*line)
		puterror(WRID, g);
	return (1);
}
