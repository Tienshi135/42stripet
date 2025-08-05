/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:10:29 by tienshi           #+#    #+#             */
/*   Updated: 2023/11/14 09:09:56 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 200
#endif

static void	line_process(int r, char **buffer, char **saved_str)
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

static char	*line_extract(char **str)
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
			buffer = ft_substr(*str, 0, i + 1);
			temp = (char *) *str;
			*str = ft_substr(*str, i + 1, ft_strlen(*str) - (i + 1));
			free(temp);
			return (buffer);
		}
		i++;
	}
	buffer = *str;
	*str = NULL;
	return (buffer);
}

static char	*fd_read(int fd, char *str)
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
