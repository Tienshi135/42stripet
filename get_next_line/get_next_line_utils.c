/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:03:54 by stripet           #+#    #+#             */
/*   Updated: 2023/10/18 15:26:02 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	c[2];

	c[0] = 0;
	c[1] = ft_strlen((char *)s);
	if (c[1] <= start || !s || len == 0)
		return (NULL);
	if (c[1] - start < len)
		buffer = (char *) malloc (sizeof(char) * (c[1] - start + 1));
	if (c[1] - start >= len)
		buffer = (char *) malloc (sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	if (start < c[1])
	{
		while (c[0] < len && s[c[0] + start])
		{
			buffer[c[0]] = s[start + c[0]];
			c[0]++;
		}
	}
	buffer[c[0]] = '\0';
	return (buffer);
}

char	*ft_strchr(const char *s, int c)
{
	char	*cursor;

	cursor = (char *) s;
	while (*cursor)
	{
		if (*cursor == (char) c)
		{
			return (cursor);
		}
		else
		{
			cursor++;
		}
	}
	if ((char) c == '\0')
		return (cursor);
	return (NULL);
}

char	*line_extract(char **str)
{
	int		i;
	char	*buffer;

	i = 0;
	while (str[i])
	{
		if (*str[i] == '\n')
		{
			buffer = ft_substr(*str, 0, i + 1);
			*str = ft_strchr(*str, '\n');
			return (buffer);
		}
		i++;
	}
	buffer = *str;
	*str = NULL;
	return (buffer);
}
