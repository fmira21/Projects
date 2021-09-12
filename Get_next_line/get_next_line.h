/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:56:27 by fmira             #+#    #+#             */
/*   Updated: 2020/11/16 19:53:08 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <stdlib.h>
# include <unistd.h>

int					get_next_line(int fd, char **line);
size_t              ft_strlen(const char *s);
void		        *ft_memmove(void *dst, const void *src, size_t len);
char                *strjoin_mod(char const *s1, char const *s2);
int                 parse_nl(char *str);
char                *line_out(char *str);
char                *trim_line(char *str);

#endif