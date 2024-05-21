/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:01:31 by ampjimen          #+#    #+#             */
/*   Updated: 2024/05/21 19:13:00 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(char *str, int c)
{
    while(*str)
    {
        if(*str == (char)c)
            return((char *)str);
        str++;
    }
    return(NULL);
}

size_t ft_strlen(const char *str)
{
    size_t i = 0;
    while(str[i])
        i++;
    return(i);
}

void ft_strcpy(char *dst, const char *src)
{
    while(*src)
        *dst++ = *src++;
    *dst = '\0';
}

char *ft_strdup(const char *src)
{
    size_t len = ft_strlen(src);
    char *dst = malloc(len);

    if(dst == NULL)
        return(NULL);
    ft_strcpy(dst, src);
    return(dst);
}

char *ft_strjoin(char *s1, char const *s2)
{
    size_t s1_len = ft_strlen(s1);
    size_t s2_len = ft_strlen(s2);
    char *join = malloc((s1_len + s2_len + 1));

    if(!s1 || !s2)
        return(NULL);
    if(!join)
        return(NULL);
    ft_strcpy(join, s1);
    ft_strcpy((join + s1_len), s2);
    free(s1);
    return(join);
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    char *line;
    char *newline;
    int count;
    int to_copy;

    line = ft_strdup(buf);
    while (!(newline = strchr(line, '\n')) && (count = read(fd, buf, BUFFER_SIZE)))
    {
        buf[count] = '\0';
        line = ft_strjoin(line, buf);
    }
    if(ft_strlen == 0)
        return(free(line), NULL);
    if(newline != NULL)
    {
        to_copy = newline - line + 1;
        ft_strcpy(buf, newline + 1);
    }
    else
    {
        to_copy = ft_strlen(line);
        buf[0] = '\0';
    }
    line[to_copy] = '\0';
    return(line);
}
