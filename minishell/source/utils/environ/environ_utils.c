/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:10:38 by marcgodel         #+#    #+#             */
/*   Updated: 2025/02/03 13:37:10 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/environ.h"
#include "../../../header/errors.h"
#include "../../../header/utils.h"

static int	find_var_end(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '_' || ft_isalpha(str[i]))
		i++;
	else
		return (-1);
	while (str[i] == '_' || ft_isalnum(str[i]))
		i++;
	if (str[i] == '\0' || ft_isspace(str[i]) || str[i] == '\''
		|| str[i] == '\"')
		return (i);
	return (-1);
}

static char	*var_extract(char *str, t_data *data)
{
	int		i;
	char	*new;

	i = 0;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	new = ft_substr(str, 0, i);
	if (!new)
		exit_err("malloc", data);
	return (new);
}

static int	get_end_of_var(char *str, int cursor, t_data *data)
{
	int	end_var;

	end_var = find_var_end(str);
	end_var += cursor;
	if (end_var <= 0)
		exit_err("Error with var expansion", data);
	return (end_var);
}

static char	*update_value(char *tok_value, int cursor, t_data *data)
{
	char	*new;

	new = ft_substr(tok_value, 0, cursor - 1);
	if (!new)
		exit_err("ft_strdup", data);
	return (new);
}

int	get_env_variable(t_token *token, int cursor, t_data *data, int len)
{
	char	*temp;
	char	*return_val;
	char	*val_env;
	int		end;

	end = get_end_of_var(&token->value[cursor], cursor, data);
	temp = var_extract(&token->value[cursor], data);
	val_env = get_val_env(temp, data, 0, 0);
	len = ft_strlen(val_env);
	free(temp);
	if (cursor > 1)
	{
		return_val = update_value(token->value, cursor, data);
		temp = safe_ft_strjoin(return_val, val_env, data);
		free(return_val);
		return_val = safe_ft_strjoin(temp, &token->value[end], data);
		free(temp);
	}
	else
		return_val = safe_ft_strjoin(val_env, &token->value[end], data);
	free(token->value);
	free(val_env);
	token->value = return_val;
	return (len);
}
