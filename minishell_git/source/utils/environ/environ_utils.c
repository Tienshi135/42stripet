/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:10:38 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/18 11:46:22 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/environ.h"
#include "../../../header/errors.h"

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

static char	*var_extract(char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	new = ft_substr(str, 0, i);
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

void	get_env_variable(t_token *token, int cursor, t_data *data)
{
	char	*temp;
	char	*return_val;
	char	*val_env;
	int		end;

	end = get_end_of_var(&token->value[cursor], cursor, data);
	temp = var_extract(&token->value[cursor]);
	val_env = get_val_env(temp, data);
	free(temp);
	if (cursor > 1)
	{
		return_val = ft_substr(token->value, 0, cursor - 1);
		temp = ft_strjoin(return_val, val_env);
		free(return_val);
		return_val = ft_strjoin(temp, &token->value[end]);
		free(temp);
	}
	else
		return_val = ft_strjoin(val_env, &token->value[end]);
	free(token->value);
	free(val_env);
	token->value = return_val;
}

void	init_env(t_data *data, char **environ)
{
	size_t	len_tab;
	size_t	i;
	char	**mini_env;

	len_tab = 0;
	i = 0;
	while (environ[len_tab])
		len_tab++;
	mini_env = malloc(sizeof(char *) * (len_tab + 1));
	mini_env[len_tab] = NULL;
	while (i != len_tab)
	{
		mini_env[i] = ft_strdup(environ[i]);
		i++;
	}
	data->envp = mini_env;
	look_shlvl(data);
}
