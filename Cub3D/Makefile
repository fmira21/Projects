# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmira <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/20 10:21:20 by fmira             #+#    #+#              #
#    Updated: 2021/04/03 16:35:07 by fmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD = cub3d.h
NAME = cub3d
U_HEAD = -I $(HEAD)
FLAGS = -Wall -Werror -Wextra
SRC = cub3d.c\
	  atoi_mod.c\
	  bmp.c\
	  config_parser.c\
	  cubutils.c\
	  directions.c\
	  file_ops.c\
	  get_next_line.c\
	  keys.c\
	  libutils.c\
	  loop_movement.c\
	  map_parser.c\
	  map_verification.c\
	  mlx_utils.c\
	  numerals.c\
	  parser_general.c\
	  parser_utils.c\
	  player_utils.c\
	  raycaster.c\
	  rc_utils.c\
	  rc_utils_two.c\
	  sprites.c\
	  spr_utils.c\
	  ss_utils/ss_raycaster.c\
	  ss_utils/ss_rc_utils_two.c\
	  ss_utils/ss_rc_utils.c\
	  ss_utils/ss_spr_utils.c\
	  ss_utils/ss_sprites.c
	  
OBJ = $(SRC:.c=.o)
MLX = ./mlx

$(NAME): $(OBJ)
	cd $(MLX) && $(MAKE)
	mv $(MLX)/libmlx.dylib .
	gcc $(FLAGS) -o $(NAME) $(OBJ) -L$(MLX) -lmlx -framework OpenGL -framework AppKit libmlx.dylib

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f screenshot.bmp

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o:%.c
	gcc -Wall -Wextra -Werror -Imlx -c $< -o $@

.PHONY: all clean fclean re