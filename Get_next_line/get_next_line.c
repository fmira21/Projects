/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:16:45 by fmira             #+#    #+#             */
/*   Updated: 2020/11/16 19:28:08 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *line_out(char *str)
{
    char *out;
    int len;
    int i;

    if (!str)
        return(0);
    len = 0;
    while (str[len] && str[len] != '\n')
        len++;
    if (!(out = (char *)malloc(sizeof(char) * (len + 1))))
        return(0);
    i = 0;
    while(str[i] && str[i] != '\n')
    {
        out[i] = str[i];
        i++;
    }
    out[i] = '\0';
    return(out);
}

char    *trim_line(char *str)
{
    char *rest;
    int llen;
    int i;

    if (!str)
        return (0);
    llen = 0;
    while (str[llen] && str[llen] != '\n')
        llen++;
    if (!str[llen])
    {
        free(str);
        return(0);
    }
    if (!(rest = (char *)malloc(sizeof(char) * ((ft_strlen(str) - llen) + 1))))
        return(0);
    llen++;
    i = 0;
    while(str[llen])
        rest[i++] = str[llen++];
    rest[i] = '\0';
    free(str);
    return(rest);
}

int		get_next_line(int fd, char **line)
{
    static char *rest;
    char *buffer;
    int rd;

    rd = 1;

    if(BUFFER_SIZE <= 0 || fd < 0 || !line)
        return(-1);
    if (!(buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char))))
        return(-1);
    while (rd != 0 && !parse_nl(rest))
    {
        rd = read(fd, buffer, BUFFER_SIZE);
        if (rd == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[rd] = '\0';
        rest = strjoin_mod(rest, buffer);
    }
    *line = line_out(rest);
    rest = trim_line(rest);
    free(buffer);
    return (!rd ? 0 : 1);
}