/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_splitting_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:30:00 by mgodel            #+#    #+#             */
/*   Updated: 2024/12/17 10:12:46 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/word_splitting.h"

static int	is_ifs_whitespace(char c, char *ifs_str)
{
	size_t	j;

	j = 0;
	while (ifs_str[j])
	{
		if (c == ifs_str[j] && (c == ' ' || c == '\t' || c == '\v'
				|| c == '\n'))
			return (1);
		j++;
	}
	return (0);
}

static int	is_ifs(char c, char *ifs_str)
{
	size_t	i;

	i = 0;
	if (!ifs_str)
		return (0);
	while (ifs_str[i] != '\0')
	{
		if (ifs_str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	get_start_ifs(char *str, t_index *ind, char *ifs_str)
{
	if (!str)
		return ;
	if (is_ifs(str[ind->i], ifs_str))
	{
		(ind->i)++;
		while (is_ifs_whitespace(str[ind->i], ifs_str))
			(ind->i)++;
		ind->start = ind->i ;
	}
}

static int	get_end_ifs(char *str, t_index *ind, char *ifs_str)
{
	if (!str)
		return (0);
	if (str[ind->i] == '\0')
		return (0);
	while (str[ind->i])
	{
		if (is_ifs(str[ind->i], ifs_str))
		{
			if (ind->i > 0)
				ind->end = ind->i - 1;
			return (1);
		}
		(ind->i)++;
	}
	return (0);
}

t_list	*split_ifs(t_list *current, char *ifs_str)
{
	t_token	*tok;
	char	*str;
	t_index	ind;

	while (1)
	{
		tok = current->content;
		str = tok->value;
		ft_bzero(&ind, sizeof(t_index));
		get_start_ifs(str, &ind, ifs_str);
		{
			if (get_end_ifs(str, &ind, ifs_str))
				current = do_split_w_s(current, ind);
			else
			{
				str = ft_strtrim(str, ifs_str);
				free(tok->value);
				tok->value = str;
				return (current);
			}
		}
	}
}
