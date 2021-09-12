/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:12:27 by fmira             #+#    #+#             */
/*   Updated: 2021/04/03 16:51:47 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_general gen;

	if (argc >= 2 && argc <= 3)
	{
		parse_config(argv[1], &gen);
		if (!(gen.win.mlx = mlx_init()))
			puterror(NOMLX, &gen);
		run_mlx(&gen);
		if (argc == 3)
			bmp_cast(&gen, argv[2]);
		gen.win.win = mlx_new_window(gen.win.mlx, gen.res.width,\
		gen.res.height, NAME);
		if (!gen.win.win)
			puterror(MLXERR, &gen);
		texdecompose(&gen);
		mlx_hook(gen.win.win, 2, 1, key_press, (void *)&gen);
		mlx_hook(gen.win.win, 17, 1, close_all, (void *)&gen);
		mlx_key_hook(gen.win.win, key_release, (void *)&gen);
		mlx_loop_hook(gen.win.mlx, loop_image, (void *)&gen);
		mlx_loop(gen.win.mlx);
	}
	else
		puterror_nomlc(ARGS);
	return (0);
}
