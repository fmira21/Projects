/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:34:11 by fmira             #+#    #+#             */
/*   Updated: 2021/04/03 17:02:13 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "errors.h"

# define MLX_SYNC_IMAGE_WRITABLE    1
# define MLX_SYNC_WIN_FLUSH_CMD     2
# define MLX_SYNC_WIN_CMD_COMPLETED 3
# define BUFFER_SIZE 32
# define MSPEED 0.2
# define RSPEED 0.2
# define NAME "Fmira's Cub3D"

typedef struct			s_bmp
{
	int					bmp_fd;
	unsigned int		bmp_size;
	unsigned int		bmp_padding;
	unsigned char		zeropad[3];
	unsigned char		header[54];
	void				*bmp_img;
	char				*bmp_addr;
	int					h_bmp;
	int					w_bmp;
	int					bmp_bpp;
	int					bmp_linel;
	int					bmp_en;
}						t_bmp;

typedef struct			s_win
{
	void				*mlx;
	void				*win;
	void				*img;
	void				*addr;
	int					line_l;
	int					bpp;
	int					en;
}						t_win;

typedef struct			s_player
{
	float				pos_x;
	float				pos_y;
	float				dir_x;
	float				dir_y;
	float				plane_x;
	float				plane_y;
	double				cam_x;
	int					m_fwd;
	int					m_bwd;
	int					m_lt;
	int					m_rt;
	int					r_rt;
	int					r_lt;

}						t_player;

typedef struct			s_map
{
	int					x_max;
	int					y_max;
	char				**map_all;
	char				**buffer;
}						t_map;

typedef struct			s_sprites
{
	int					x;
	int					y;
}						t_sprites;

typedef struct			s_sprtr
{
	float				sprite_x;
	float				sprite_y;
	float				invdet;
	float				transform_x;
	float				transform_y;
	int					spritescreen_x;
	int					sprite_h;
	int					sprite_w;
	int					sprite_dsx;
	int					sprite_dex;
	int					sprite_dsy;
	int					sprite_dey;
	int					tex_x;
	int					tex_y;
	int					d;
	int					pos;
	float				zbuffer[4000];
	int					x;
	int					y;
}						t_sprtr;

typedef struct			s_raytools
{
	float				camera_x;
	float				raydir_x;
	float				raydir_y;
	int					map_x;
	int					map_y;
	float				sidedist_x;
	float				sidedist_y;
	float				deltadist_x;
	float				deltadist_y;
	float				pwd;
	int					r_hit;
	int					step_x;
	int					step_y;
	int					side;
	int					lheight;
	int					draw_start;
	int					draw_end;
	float				wall_x;
	int					tex_x;
	int					tex_y;
	int					pos;
	float				step;
	float				tex_pos;
	float				old_dir_xr;
	float				old_plane_xr;
	float				old_dir_xl;
	float				old_plane_xl;
}						t_raytools;

typedef struct			s_textures
{
	void				*t1_img;
	char				*t1_raw;
	char				*t1_addr;
	int					t1_height;
	int					t1_width;
	int					t1_linel;
	int					t1_bpp;
	int					t1_en;
	void				*t2_img;
	char				*t2_raw;
	char				*t2_addr;
	int					t2_height;
	int					t2_width;
	int					t2_linel;
	int					t2_bpp;
	int					t2_en;
	void				*t3_img;
	char				*t3_raw;
	char				*t3_addr;
	int					t3_height;
	int					t3_width;
	int					t3_linel;
	int					t3_bpp;
	int					t3_en;
	void				*t4_img;
	char				*t4_raw;
	char				*t4_addr;
	int					t4_height;
	int					t4_width;
	int					t4_linel;
	int					t4_bpp;
	int					t4_en;
	void				*out_img;
	char				*out_raw;
	int					out_height;
	int					out_linel;
	int					out_width;
	int					out_bpp;
	int					out_en;
	void				*spr_img;
	char				*spr_raw;
	void				*spr_mlx;
	char				*spr_addr;
	int					spr_height;
	int					spr_width;
	int					spr_linel;
	int					spr_bpp;
	int					spr_en;
	int					spr_count;
	int					spr_hit;
	int					*spr_order;
	t_sprites			*sprites;
	t_sprtr				sprites_tr;
}						t_textures;

typedef struct			s_colors
{
	int					floor_r;
	int					floor_g;
	int					floor_b;
	int					ceil_r;
	int					ceil_g;
	int					ceil_b;
}						t_colors;

typedef struct			s_res
{
	int					height;
	int					width;
	int					h_screen;
	int					w_screen;
}						t_res;

typedef struct			s_general
{
	t_res				res;
	t_colors			clr;
	t_textures			text;
	t_map				map;
	t_player			plr;
	t_win				win;
	t_raytools			rtools;
	t_bmp				bmp;
	char				rest;
	int					resolution;
	int					floor;
	int					ceiling;
	int					tex1;
	int					tex2;
	int					tex3;
	int					tex4;
	int					sprite;
	int					player;
	int					bmp_saved;
	char				**config;
}						t_general;

int						loop_image(t_general *g);
void					run_mlx(t_general *g);
void					check_colentries(char c, t_general *g);
void					check_colors(int d, t_general *g);
void					ft_bzero(void *s, size_t n);
size_t					ft_strlen(const char *s);
void					ft_putchar(char c);
void					ft_putstr(char *str);
void					ft_putendl(char *s);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					puterror(char *msg, t_general *g);
void					puterror_nomlc(char *msg);
void					exc_entry(char *str, t_general *g, char *message);
void					print_config(char **map);
int						ft_isdigit(int c);
int						get_next_line(int fd, char **line);
int						ft_atoi_res(const char *str);
int						ft_atoi_col(const char *str);
unsigned char			*ft_itoa(int n);
int						close_all(t_general *g);
void					draw_sprites(t_general *g);
void					cast_rays(t_general *g);
void					pixel_put(t_general *g, int x, int y, int color);
void					bmp_entry(t_general *g, char *str);
int						collision(char next, t_general *g);
t_sprites				*get_sprites(t_general *g);
void					draw_sprites(t_general *g);
void					texdecompose(t_general *g);
void					check_boundaries(t_general *g, int x, int y);
void					revert_map(t_general *g);
void					check_entries(t_general *g);
int						movement_fb(t_general *g);
int						movement_lr(t_general *g);
void					rotation_left(t_general *g);
void					rotation_right(t_general *g);
int						key_press(int keycode, t_general *g);
int						key_release(int keycode, t_general *g);
void					find_player(t_general *g);
void					set_player(t_general *g, int x, int y);
void					check_void(t_general *g);
void					parse_map(t_general *g, char **lconfig);
void					sprite_checker(t_general *g);
void					texture_checker_12(int num, t_general *g);
void					texture_checker_34(int num, t_general *g);
void					make_tex1(char *str, t_general *g);
void					make_tex2(char *str, t_general *g);
void					make_tex3(char *str, t_general *g);
void					make_tex4(char *str, t_general *g);
void					make_sprite(char *str, t_general *g);
void					bmp_cast(t_general *g, char *str);
void					confverify(t_general *g);
void					init_params(t_general *g);
char					**gnl_config(char **lconfig, char **tmp, int fd);
char					**parse_parameters(t_general *g, char **lines);
int						parse_config(char *file, t_general *g);
void					make_resolution(char *str, t_general *g);
void					make_floor(char *str, t_general *g);
void					make_ceiling(char *str, t_general *g);
int						conf_crawler(char *str, t_general *g);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					dir_n(t_general *g);
void					dir_s(t_general *g);
void					dir_w(t_general *g);
void					dir_e(t_general *g);
void					check_dir(t_general *g, int i, int j);
void					init_drs(t_general *g, int y);
int						sum_rgb(int r, int g, int b);
void					draw_flceil(t_general *g, int x, int draw_start, \
						int draw_end);
void					init_rc(t_general *g, int x);
void					calc_deltadist(t_general *g);
void					calc_step_sided(t_general *g);
void					calc_mapside(t_general *g, char **map);
void					calc_pwd(t_general *g);
void					calc_tx(t_general *g);
void					define_txtwo(t_general *g);
void					define_txthree(t_general *g);
void					define_txfour(t_general *g);
int						fill_sprstr(t_general *g, char **map, t_sprites *spr, \
						int i);
char					*ignore_spaces(char *str);
char					*ft_strnstr(const char *hayst, const char *needle, \
						size_t len);
void					check_file(char *file);
void					bmp_cast_rays(t_general *g);
void					bmp_calc_dsde(t_general *g);
void					bmp_draw_texture(t_general *g, int x);
void					bmp_pixel_put(t_general *g, int x, int y, int color);
void					bmp_draw_flceil(t_general *g, int x, int draw_start, \
						int draw_end);
void					bmp_init_rc(t_general *g, int x);
void					bmp_init_drs(t_general *g, int y);
void					bmp_draw_sprites(t_general *g);
void					bmp_calc_tx(t_general *g);
void					bmp_calc_step_sided(t_general *g);
void					bmp_calc_mapside(t_general *g, char **map);
void					bmp_calc_pwd(t_general *g);
void					bmp_define_txtwo(t_general *g);
void					bmp_define_txthree(t_general *g);
void					bmp_define_txfour(t_general *g);
void					bmp_calc_deltadist(t_general *g);

#endif
