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
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

char	*fd_extract(int fd, const char *str)
{
	char	*buffer;
	int		length;

	if (!str)
	{
		buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		if (read(fd, buffer, BUFFER_SIZE) == -1 || !*buffer)
		{
			free(buffer);
			return (NULL);
		}
		length = ft_strlen(buffer);
		buffer[length] = '\0';
		return (buffer);
	}
	return ((char *)str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	buffer = fd_extract(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = line_extract(&buffer);
	return (line);
}
