/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_splitting_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:23:31 by mgodel            #+#    #+#             */
/*   Updated: 2024/12/17 10:12:16 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/word_splitting.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static void	get_start(char *str, t_index *ind)
{
	if (!str)
		return ;
	if (is_whitespace(str[ind->i]))
	{
		ind->i++;
		while (is_whitespace(str[ind->i]))
			ind->i++;
		ind->start = ind->i;
		return ;
	}
}

static int	get_end(char *str, t_index *ind)
{
	if (!str)
		return (0);
	if (str[ind->i] == '\0')
		return (0);
	while (str[ind->i])
	{
		if (is_whitespace(str[ind->i]))
		{
			if (ind->i > 0)
				ind->end = ind->i - 1;
			return (1);
		}
		(ind->i)++;
	}
	return (0);
}

t_list	*split_whitespace(t_list *current)
{
	t_token	*tok;
	char	*str;
	t_index	ind;

	while (1)
	{
		tok = current->content;
		str = tok->value;
		ft_bzero(&ind, sizeof(t_index));
		get_start(str, &ind);
		{
			if (get_end(str, &ind))
				current = do_split_w_s(current, ind);
			else
			{
				str = ft_strtrim(str, " \n\t\v");
				free(tok->value);
				tok->value = str;
				return (current);
			}
		}
	}
}
