/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:07:18 by fmira             #+#    #+#             */
/*   Updated: 2021/01/01 16:13:58 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_flags
{
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

int					ft_printf(const char *str, ...);
int					parse_input(const char *save, va_list args);
int					is_type(int c);
int					is_flag(int c);

int					flag_dot(const char *save, int start, \
					t_flags *flags, va_list args);
t_flags				flag_minus(t_flags flags);
t_flags				flag_width(va_list args, t_flags flags);
t_flags				flag_digit(char c, t_flags flags);

int					processor(int c, t_flags flags, va_list args);
int					proc_char(char c, t_flags flags);
int					proc_string(char *str, t_flags flags);
int					proc_pointer(unsigned long pointer, t_flags flags);
int					proc_int(int i, t_flags flags);
int					proc_uint(unsigned int unsi, t_flags flags);
int					proc_hex(unsigned int ui, int lower, t_flags flags);
int					write_hex(char *hexa, t_flags flags);
int					proc_percent(t_flags flags);

int					add_width(int width, int minus, int has_zero);
int					put_str_wprec(char *str, int precision);

int					ft_putchar(int c);
int					ft_tolower(int c);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
int					ft_isdigit(int c);
char				*ft_itoa(int n);
char				*uitoa(unsigned int n);

#endif
