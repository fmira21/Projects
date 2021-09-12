/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:25:02 by fmira             #+#    #+#             */
/*   Updated: 2021/04/03 17:06:10 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				loop_image(t_general *g)
{
	movement_fb(g);
	movement_lr(g);
	rotation_left(g);
	rotation_right(g);
	cast_rays(g);
	draw_sprites(g);
	mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.img, 0, 0);
	mlx_do_sync(g->win.mlx);
	return (0);
}

void			run_mlx(t_general *g)
{
	g->win.img = mlx_new_image(g->win.mlx, g->res.width + 1, \
	g->res.height);
	g->win.addr = mlx_get_data_addr(g->win.img, &g->win.bpp, \
	&g->win.line_l, &g->win.en);
	if (!g->win.img || !g->win.addr)
		puterror(MLXERR, g);
}

void			texdecompose(t_general *g)
{
	if (!(g->text.t1_img = mlx_xpm_file_to_image(g->win.mlx, \
	g->text.t1_addr, &g->text.t1_width, &g->text.t1_height)))
		puterror(INVTEX1, g);
	if (!(g->text.t2_img = mlx_xpm_file_to_image(g->win.mlx, \
	g->text.t2_addr, &g->text.t2_width, &g->text.t2_height)))
		puterror(INVTEX2, g);
	if (!(g->text.t3_img = mlx_xpm_file_to_image(g->win.mlx, \
	g->text.t3_addr, &g->text.t3_width, &g->text.t3_height)))
		puterror(INVTEX3, g);
	if (!(g->text.t4_img = mlx_xpm_file_to_image(g->win.mlx, \
	g->text.t4_addr, &g->text.t4_width, &g->text.t4_height)))
		puterror(INVTEX4, g);
	if (!(g->text.spr_img = mlx_xpm_file_to_image(g->win.mlx, \
	g->text.spr_addr, &g->text.spr_width, &g->text.spr_height)))
		puterror(INVTEX5, g);
	g->text.t1_raw = mlx_get_data_addr(g->text.t1_img, \
	&g->text.t1_bpp, &g->text.t1_linel, &g->text.t1_en);
	g->text.t2_raw = mlx_get_data_addr(g->text.t2_img, \
	&g->text.t2_bpp, &g->text.t2_linel, &g->text.t2_en);
	g->text.t3_raw = mlx_get_data_addr(g->text.t3_img, \
	&g->text.t3_bpp, &g->text.t3_linel, &g->text.t3_en);
	g->text.t4_raw = mlx_get_data_addr(g->text.t4_img, \
	&g->text.t4_bpp, &g->text.t4_linel, &g->text.t4_en);
	g->text.spr_raw = mlx_get_data_addr(g->text.spr_img, \
	&g->text.spr_bpp, &g->text.spr_linel, &g->text.spr_en);
}
