/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:10:29 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/25 16:10:29 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

void	*gnl_bzero(void *s, size_t n)
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

void	*gnl_calloc(size_t nmemb, size_t size)
{
	char	*buffer;
	size_t	s;

	s = nmemb * size;
	buffer = (char *) malloc(s);
	if (!buffer)
		return (NULL);
	else
	{
		gnl_bzero(buffer, s);
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
		*saved_str = gnl_strjoin(*saved_str, *buffer);
	if (temp && temp != *saved_str)
		free(temp);
}

char	*fd_read(int fd, char *str)
{
	char	*buffer;
	int		r;

	r = BUFFER_SIZE;
	buffer = (char *) gnl_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (r == BUFFER_SIZE && !gnl_strchr(buffer, '\n'))
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
	static char	*buffer[1024];
	char		*line;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	buffer[fd] = fd_read(fd, buffer[fd]);
	if (!buffer[fd])
	{
		buffer[fd] = NULL;
		return (buffer[fd]);
	}
	if (!*(buffer[fd]))
	{
		buffer[fd] = NULL;
		return (buffer[fd]);
	}
	line = line_extract(&buffer[fd]);
	return (line);
}
