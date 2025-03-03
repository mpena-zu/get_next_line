/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:01:17 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/02/27 22:38:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*total;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	total = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (total == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		total[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		total[i + j] = s2[j];
		j++;
	}
	total[i + j] = '\0';
	return (total);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*total;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		total = (char *)malloc(1);
		if (!total)
			return (NULL);
		total[0] = '\0';
		return (total);
	}
	total = (char *)malloc(len + 1);
	if (!total)
		return (NULL);
	while (i < len)
	{
		total[i] = s[i + start];
		i++;
	}
	return (total[i] = '\0', total);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (i < ft_strlen(s))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
