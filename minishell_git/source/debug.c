/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:24:08 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/22 21:40:45 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../header/structures.h"
#include <unistd.h>
#include <stdlib.h>

void	print_tab_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		printf("str (%d):", i);
		printf("%s\n", str[i]);
		i++;
	}
}

void	print_segment(t_segment *seg, int i)
{
	if (!seg)
	{
		printf("no seg\n");
		return ;
	}
	printf("segment num (%d):\n", i);
	if (seg->argv)
	{
		printf("argv:\n");
		print_tab_str(seg->argv);
	}
	if (seg->cmd_path)
		printf("cmd_path = %s\n", seg->cmd_path);
	printf("\nis_builtin = %d\n", (int)seg->is_builtin);
}

void	print_list_seg(t_list *segments)
{
	t_segment	*seg;
	t_list		*curr;
	int			i;

	i = 0;
	curr = segments;
	while (curr)
	{
		seg = (t_segment *)curr->content;
		print_segment(seg, i);
		i++;
		curr = curr->next;
	}
}

void	print_lst(t_list *lst)
{
	t_token	*token;

	while (lst)
	{
		token = lst->content;
		printf("type: %d, value: %s, status: %d\n", token->type,
			token->value, token->status);
		lst = lst->next;
	}
}
