/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:15:58 by marcgodel         #+#    #+#             */
/*   Updated: 2025/01/07 10:18:14 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

static char	*extract(char *line, char *buff)
{
	char	*tmp;
	char	*new;
	size_t	i;

	tmp = ft_memchr(buff, '\n', ft_strlen(buff));
	if (!tmp)
	{
		buff[0] = 0;
		return (line);
	}
	ft_memmove(buff, tmp + 1, (ft_strlen(tmp + 1) + 1));
	tmp = ft_memchr(line, '\n', ft_strlen(line));
	*(tmp + 1) = 0;
	new = malloc(sizeof(char) * ft_strlen(line) + 1);
	if (!new)
	{
		free(line);
		return (NULL);
	}
	i = ft_strlen(line);
	ft_memmove(new, line, i);
	new[i] = 0;
	free(line);
	return (new);
}

static char	*ft_safe_strjoin(char *line, char *buff)
{
	char	*new;

	if (!line)
		return (ft_strdup(buff));
	new = ft_strjoin((const char *)line, (const char *) buff);
	if (line)
		free(line);
	return (new);
}

static char	*read_line(int fd, char *buff)
{
	ssize_t	ret;
	char	*line;

	ret = BUFFER_SIZE;
	line = NULL;
	if (buff[0] != '\0')
		line = ft_strdup(buff);
	while (ret == BUFFER_SIZE && !ft_memchr(buff, '\n', ft_strlen(buff)))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
		{
			buff[0] = 0;
			if (line)
				free(line);
			return (NULL);
		}
		buff[ret] = 0;
		if (ret == 0)
			break ;
		line = ft_safe_strjoin(line, buff);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = read_line(fd, buff);
	if (!line)
		return (NULL);
	line = extract(line, buff);
	return (line);
}
