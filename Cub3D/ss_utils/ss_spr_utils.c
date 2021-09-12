/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_spr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:12:24 by fmira             #+#    #+#             */
/*   Updated: 2021/04/01 11:59:05 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			bmp_init_drs(t_general *g, int y)
{
	g->text.sprites_tr.d = y * 256 - g->bmp.h_bmp * 128 \
	+ g->text.sprites_tr.sprite_h * 128;
	g->text.sprites_tr.tex_y = ((g->text.sprites_tr.d \
	* g->text.spr_height) / g->text.sprites_tr.sprite_h) \
	/ 256;
	if (g->text.sprites_tr.tex_y < 0)
		g->text.sprites_tr.tex_y = 0;
	g->text.sprites_tr.pos = (g->text.sprites_tr.tex_y * \
	g->text.spr_linel \
	+ g->text.sprites_tr.tex_x * (g->text.spr_bpp / 8));
}
