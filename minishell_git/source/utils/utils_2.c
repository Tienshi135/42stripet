/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:00:28 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/11 09:03:20 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../header/utils.h"
#include <stdio.h>
#include <termios.h>

void	enable_echoctl(void)
{
	struct termios	s_tmp;

	if (tcgetattr(STDIN_FILENO, &s_tmp) == -1)
	{
		perror("tcgetattr");
		exit(1);
	}
	s_tmp.c_lflag |= ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &s_tmp) == -1)
	{
		perror("tcgetattr");
		exit(1);
	}
}

void	disable_echoctl(void)
{
	struct termios	s_tmp;

	if (tcgetattr(STDIN_FILENO, &s_tmp) == -1)
	{
		perror("tcgetattr");
		exit(1);
	}
	s_tmp.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &s_tmp) == -1)
	{
		perror("tcgetattr");
		exit(1);
	}
}

int	string_cmp(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return ((int)str1[i] - (int)str2[i]);
}

int	is_redir_type(t_type type)
{
	if (type > WORD && type < PIPE)
		return (1);
	return (0);
}
