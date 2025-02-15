/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:37:11 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/19 08:25:42 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/expansions.h"
#include "../header/errors.h"
#include "../header/tokenize.h"
#include "../header/environ.h"
#include "../header/word_splitting.h"
#include "../header/structures.h"
#include "../header/utils.h"

static void	get_exit_status(t_token *buff, int cursor, t_data *data)
{
	char	*exit_value;
	char	*start_str;
	char	*new_str;
	char	*str_tmp;

	exit_value = ft_itoa(data->return_v);
	if (!exit_value)
		err_clean(data);
	start_str = ft_substr(buff->value, 0, cursor);
	if (!start_str)
		err_clean(data);
	str_tmp = ft_strjoin(start_str, exit_value);
	if (!str_tmp)
		err_clean(data);
	free(exit_value);
	free(start_str);
	new_str = ft_strjoin(str_tmp, &(buff->value[cursor + 2]));
	if (!new_str)
		err_clean(data);
	free(str_tmp);
	free(buff->value);
	buff->value = new_str;
}

static void	do_exp_2(t_token *buff, t_data *data, t_status status, int *i)
{
	int	len;

	if (status != SINGLE_QUOTED && ft_strncmp(&(buff->value[*i]), "$?", 3)
		== 0)
	{
		get_exit_status(buff, *i, data);
		*i = 0;
		status = UNQUOTED;
	}
	else if (status != SINGLE_QUOTED && buff->value[*i] == '$'
		&& (buff->value[*i + 1] && buff->value[*i +1] != '\"'))
	{
		len = get_env_variable(buff, *i + 1, data, 0);
		*i = *i + len;
		status = UNQUOTED;
	}
	else
		(*i)++;
}

static void	do_exp(t_list *list, t_data *data)
{
	t_token		*buff;
	int			i;

	i = 0;
	if (!list)
		return ;
	buff = (t_token *)list->content;
	while (buff->value[i])
	{
		do_exp_2(buff, data, buff->status, &i);
		if (!buff->value)
			buff->value = ft_calloc(1, sizeof(char));
	}
}

void	expansion(t_data *data)
{
	t_token	*curr;
	t_list	*tmp;

	tmp = data->tokens;
	while (tmp)
	{
		curr = (t_token *)tmp->content;
		if ((curr->status == UNQUOTED && ft_strchr(curr->value, '$'))
			|| (curr->status == DOUBLE_QUOTED
				&& ft_strchr(curr->value, '$')))
		{
			do_exp(tmp, data);
			if (curr->status == UNQUOTED)
				tmp = word_splitting(tmp, data);
		}
		tmp = tmp->next;
	}
	quote_removal(data);
}
