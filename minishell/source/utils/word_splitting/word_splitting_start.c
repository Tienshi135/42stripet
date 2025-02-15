/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_splitting_start.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:37:11 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/18 08:29:26 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/word_splitting.h"
#include "../../../header/environ.h"

t_list	*do_split_w_s(t_list *current, t_index ind)
{
	t_list	*new_node;
	t_token	*new_tok;
	t_token	*tok;
	char	*first_part;
	size_t	len_new_str;

	len_new_str = ind.i - ind.start;
	new_tok = ft_calloc(1, sizeof(t_token));
	if (!new_tok)
		exit (1);
	first_part = malloc(sizeof(char) * (len_new_str + 1));
	if (!first_part)
		exit (1);
	first_part[len_new_str] = 0;
	tok = current->content;
	new_tok->value = ft_strdup(&tok->value[ind.i]);
	first_part = ft_substr(tok->value, ind.start, len_new_str);
	free(tok->value);
	tok->value = first_part;
	new_node = ft_lstnew((void *)new_tok);
	new_node->next = current->next;
	new_node->previous = current;
	current->next = new_node;
	return (new_node);
}

t_list	*word_splitting(t_list *current, t_data *data)
{
	char	*ifs_str;
	t_list	*tmp;

	if (!current)
		return (NULL);
	ifs_str = get_val_env("IFS", data, 0, 0);
	if (ifs_str)
	{
		tmp = split_ifs(current, ifs_str);
		return (tmp);
	}
	else
		tmp = split_whitespace(current);
	return (tmp);
}
