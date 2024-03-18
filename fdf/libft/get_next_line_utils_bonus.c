/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:11:35 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/25 16:11:35 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	gnl_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	int		i;
	int		len[2];

	len[0] = gnl_strlen((char *)s1);
	len[1] = gnl_strlen((char *)s2);
	buffer = (char *) malloc(sizeof(char) * (len[0] + len[1] + 1));
	i = 0;
	if (!buffer)
		return (NULL);
	while (s1 && *s1)
	{
		buffer[i] = *s1;
		s1++;
		i++;
	}
	while (s2 && *s2)
	{
		buffer[i] = *s2;
		s2++;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*gnl_strchr(const char *s, int c)
{
	char	*cursor;

	if (!s)
		return (NULL);
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

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	c[2];

	c[0] = 0;
	c[1] = gnl_strlen((char *)s);
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

char	*line_extract(char **str)
{
	int		i;
	char	*buffer;
	void	*temp;

	i = 0;
	if (!str || !*str)
		return (NULL);
	while ((*str)[i])
	{
		if ((*str)[i] == '\n')
		{
			buffer = gnl_substr(*str, 0, i + 1);
			temp = (char *) *str;
			*str = gnl_substr(*str, i + 1, gnl_strlen(*str) - (i + 1));
			free(temp);
			return (buffer);
		}
		i++;
	}
	buffer = *str;
	*str = NULL;
	return (buffer);
}
