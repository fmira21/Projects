/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:00:39 by fmira             #+#    #+#             */
/*   Updated: 2021/04/03 16:52:41 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_tex1(char *str, t_general *g)
{
	int fd;

	while (*str == ' ')
		str++;
	texture_checker_12(1, g);
	if ((fd = open(str, O_RDONLY)) < 0)
		puterror(NOFILE1, g);
	close(fd);
	g->text.t1_addr = str;
}

void	make_tex2(char *str, t_general *g)
{
	int fd;

	while (*str == ' ')
		str++;
	texture_checker_12(2, g);
	if ((fd = open(str, O_RDONLY)) < 0)
		puterror(NOFILE2, g);
	close(fd);
	g->text.t2_addr = str;
}

void	make_tex3(char *str, t_general *g)
{
	int fd;

	while (*str == ' ')
		str++;
	texture_checker_34(3, g);
	if ((fd = open(str, O_RDONLY)) < 0)
		puterror(NOFILE3, g);
	close(fd);
	g->text.t3_addr = str;
}

void	make_tex4(char *str, t_general *g)
{
	int fd;

	while (*str == ' ')
		str++;
	texture_checker_34(4, g);
	if ((fd = open(str, O_RDONLY)) < 0)
		puterror(NOFILE4, g);
	close(fd);
	g->text.t4_addr = str;
}

void	make_sprite(char *str, t_general *g)
{
	int fd;

	if (g->sprite == 1)
		puterror(SPRMUL, g);
	while (*str == ' ')
		str++;
	if ((fd = open(str, O_RDONLY)) < 0)
		puterror(NOSPRITEF, g);
	close(fd);
	g->text.spr_addr = str;
	sprite_checker(g);
	g->sprite = 1;
}
