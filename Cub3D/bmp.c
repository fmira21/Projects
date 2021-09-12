/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:04:03 by fmira             #+#    #+#             */
/*   Updated: 2021/04/01 11:55:48 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		fill_bmp(t_general *g)
{
	int height;
	int color;
	int width;

	height = g->bmp.h_bmp - 1;
	while (height >= 0)
	{
		width = 0;
		while (width < g->bmp.w_bmp)
		{
			color = *(unsigned int *)(g->bmp.bmp_addr + \
			(height * g->bmp.bmp_linel + width * (g->bmp.bmp_bpp / 8)));
			write(g->bmp.bmp_fd, &color, 3);
			width++;
		}
		write(g->bmp.bmp_fd, g->bmp.zeropad, g->bmp.bmp_padding);
		height--;
	}
}

void		init_header(t_general *g)
{
	unsigned int	*fsize;
	unsigned int	*fwidth;
	unsigned int	*fheight;

	g->bmp.header[0] = 0x42;
	g->bmp.header[1] = 0x4d;
	g->bmp.header[10] = 0x36;
	g->bmp.header[14] = 0x28;
	g->bmp.header[26] = 0x01;
	g->bmp.header[28] = 0x18;
	g->bmp.header[38] = 0x13;
	g->bmp.header[39] = 0x0B;
	g->bmp.header[42] = 0x13;
	g->bmp.header[43] = 0x0B;
	fsize = (unsigned int*)&g->bmp.header[2];
	*fsize = g->bmp.bmp_size;
	fwidth = (unsigned int*)&g->bmp.header[18];
	*fwidth = g->bmp.w_bmp;
	fheight = (unsigned int*)&g->bmp.header[22];
	*fheight = g->bmp.h_bmp;
	write(g->bmp.bmp_fd, g->bmp.header, 54);
	fill_bmp(g);
}

int			shoot_scene(t_general *g)
{
	g->bmp.bmp_padding = (4 - (g->bmp.w_bmp * 3) % 4) % 4;
	g->bmp.bmp_size = 54 + ((g->bmp.w_bmp * 3 * g->bmp.h_bmp) + \
	(g->bmp.bmp_padding * g->bmp.h_bmp));
	if ((g->bmp.bmp_fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0777 | \
	O_TRUNC | O_APPEND)) < 0)
		return (0);
	ft_bzero(g->bmp.header, 54);
	ft_bzero(g->bmp.zeropad, 3);
	init_header(g);
	return (1);
}

void		bmp_entry(t_general *g, char *str)
{
	if (ft_strncmp(str, "--save", ft_strlen(str)) != 0 \
	|| ft_strlen(str) != ft_strlen("--save"))
		puterror(NOSSARG, g);
	g->bmp_saved = 1;
	if (!shoot_scene(g))
		puterror(UNSCR, g);
	write(1, "Screenshot saved.\nCub3D will be closed now.\n", 44);
	close_all(g);
}

void		bmp_cast(t_general *g, char *str)
{
	if (g->bmp.w_bmp > 4000)
		g->bmp.w_bmp = 4000;
	if (g->bmp.h_bmp > 4000)
		g->bmp.h_bmp = 4000;
	g->bmp.bmp_img = mlx_new_image(g->win.mlx, g->bmp.w_bmp + 1, \
	g->bmp.h_bmp);
	g->bmp.bmp_addr = mlx_get_data_addr(g->bmp.bmp_img, &g->bmp.bmp_bpp, \
	&g->bmp.bmp_linel, &g->bmp.bmp_en);
	if (!g->bmp.bmp_img || !g->bmp.bmp_addr)
		puterror(MLXERR, g);
	texdecompose(g);
	bmp_cast_rays(g);
	bmp_draw_sprites(g);
	bmp_entry(g, str);
}
