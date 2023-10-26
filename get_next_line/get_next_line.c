/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:04:02 by stripet           #+#    #+#             */
/*   Updated: 2023/10/18 15:21:59 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 200
#endif

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*cursor;

	i = 0;
	cursor = s;
	while (i < n)
	{
		cursor[i] = '\0';
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*buffer;
	size_t	s;

	s = nmemb * size;
	buffer = (char *) malloc(s);
	if (!buffer)
		return (NULL);
	else
	{
		ft_bzero(buffer, s);
		return (buffer);
	}
}

void	line_process(int r, char **buffer, char **saved_str)
{
	void	*temp;

	temp = (char *) *saved_str;
	if (r < BUFFER_SIZE)
		(*buffer)[r] = '\0';
	if (r != 0)
		*saved_str = ft_strjoin(*saved_str, *buffer);
	if (temp && temp != *saved_str)
		free(temp);
}

char	*fd_read(int fd, char *str)
{
	char	*buffer;
	int		r;

	r = BUFFER_SIZE;
	buffer = (char *) ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (r == BUFFER_SIZE && !ft_strchr(buffer, '\n'))
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			if (str)
				free(str);
			return (NULL);
		}
		line_process(r, &buffer, &str);
	}
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = fd_read(fd, buffer);
	if (!buffer)
	{
		buffer = NULL;
		return (buffer);
	}
	if (!*buffer)
	{
		buffer = NULL;
		return (buffer);
	}
	line = line_extract(&buffer);
	return (line);
}
