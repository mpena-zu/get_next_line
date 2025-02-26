/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:57:04 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/02/19 12:57:06 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int read_line(int fd, char *words, char *buffer)
{
    int 
}

char    *get_next_line(int fd)
{
    char    *words;
    char    *buffer;
    int     bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(buffer);
            return (NULL);
        }

    }
    return (words);
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