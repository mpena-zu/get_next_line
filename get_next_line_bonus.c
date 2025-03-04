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

static char	*read_line(int fd, char *str)
{
	char	*new_str_line;
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	new_str_line = NULL;
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(str);
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

static char	*get_line(char *str)
{
	int		len;
	char	*new_str;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	new_str = ft_substr(str, 0, len + 1);
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	return (new_str);
}

static char	*get_rest(char *str)
{
	int		len;
	char	*rest;

	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	if (!str[len])
	{
		free(str);
		return (NULL);
	}
	rest = ft_substr(str, len + 1, (ft_strlen(str) - (len)));
	if (!rest)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (rest);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str[fd])
		str[fd] = ft_strdup("");
	str[fd] = read_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	if (!str[fd][0])
	{
		free(str[fd]);
		return (str[fd] = NULL, NULL);
	}
	line = get_line(str[fd]);
	str[fd] = get_rest(str[fd]);
	if (!str[fd])
	{
		free(str[fd]);
		str[fd] = NULL;
	}
	return (line);
}

/* int main(void)
{
	int     fd1 = open("ejemplo1.txt", O_RDONLY); 
	int		fd2 = open("ejemplo2.txt", O_RDONLY);
	int		fd3 = open("ejemplo3.txt", O_RDONLY);
	char    *word1;
	char	*word2;
	char	*word3;

	while (1)
	{
		word1 = get_next_line(fd1);
		word2 = get_next_line(fd2);
		word3 = get_next_line(fd3);
		if (word1 == NULL && word2 == NULL && word3 == NULL)
        	break;
		if (word1 != NULL)
		{
			printf("%s", word1);
			free(word1);
		}
		if (word2 != NULL)
		{
			printf("%s", word2);
			free(word2);
		}
		if (word3 != NULL)
		{
			printf("%s", word3);
			free(word3);
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */