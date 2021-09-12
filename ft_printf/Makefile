# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmira <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/01 16:07:28 by fmira             #+#    #+#              #
#    Updated: 2021/01/01 16:23:58 by fmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
		parser.c \
		flag_parsers.c \
		processor.c \
		c_char.c \
		d_i_int.c \
		p_pointer.c \
		s_string.c \
		u_uint.c \
		x_hex.c \
		write_x.c \
		percent.c \
		ft_itoa.c \
		uitoa.c \
		aux_custom.c \
		aux_lib.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEAD = -I ./

$(NAME): 
		gcc -c $(HEAD) $(FLAGS) $(SRC)
		ar -rc $(NAME) $(OBJ)
		ranlib $(NAME)

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re



