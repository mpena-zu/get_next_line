/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:57:04 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/02/27 22:55:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char    *read_line(int fd, char *str)
{
    char    *new_str_line;
    char    *buffer;
    int     bytes_read;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    new_str_line = "";
    bytes_read = 1;
    while (bytes_read != 0 && !ft_strchr(str, '\n'))
    {   
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        new_str_line = ft_strjoin(str, buffer);
        free(str);
        str = new_str_line;
    }
    free(buffer);
    return (str);
}

char    *get_line(char *str)
{
    int     len;
    char    *new_str;

    if (!str)
        return (NULL);
    len = 0;
    while (str[len] != '\n' && str[len])
        len++;
    new_str = ft_substr(str, 0, len + 1);
    return (new_str);
}

char    *get_rest(char *str)
{
    int     len;
    char    *rest;

    len = 0;
    while (str[len] != '\n' && str[len])
        len++;
    if (!str[len])
    {
        free(str);
        return (NULL);
    }
    rest = ft_substr(str, len + 1, (ft_strlen(str) - (len)));
    free(str);
    return (rest);
}

char    *get_next_line(int fd)
{
    char            *line;
    static char     *str;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!str)
        str = ft_strdup("");
    str = read_line(fd, str);
    if (!str)
        return (NULL);
    if (!str[0])
    {
        free(str);
        str = NULL;
        return (str);
    }
    line = get_line(str);
    str = get_rest(str);
    return (line);
}

int main(void)
{
    int     fd = open("ejemplo.txt", O_RDONLY); 
    char    *word;

    word = get_next_line(fd);
    while (word != NULL)
    {
        printf("%s", word);
        free(word);
        word = get_next_line(fd);
    }
    close(fd);
    return (0);
}