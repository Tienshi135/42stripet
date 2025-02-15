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
#include "../../header/builtins.h"
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

void	check_builtin_segment(t_list *seg_list)
{
	t_list		*tmp;
	t_segment	*tmp_seg;
	t_bool		prev_buil;

	prev_buil = false;
	if (!seg_list)
		return ;
	tmp = seg_list;
	while (tmp)
	{
		tmp_seg = (t_segment *)tmp->content;
		if (tmp_seg->argv)
		{
			if (prev_buil == true)
				tmp_seg->prev_builtin = true;
			if (is_builtin(tmp_seg->argv[0]))
			{
				tmp_seg->is_builtin = true;
				prev_buil = true;
			}
			else
				prev_buil = false;
		}
		tmp = tmp->next;
	}
}
