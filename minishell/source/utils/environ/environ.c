/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:12:41 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/16 20:08:52 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/environ.h"
#include "../../../header/builtins.h"
#include "../../../header/errors.h"

void	delete_env_last_command(t_data *data)
{
	char	*argument[3];
	char	first[1];
	char	second[2];

	first[0] = '\0';
	second[0] = '_';
	second[1] = '\0';
	argument[0] = first;
	argument[1] = second;
	argument[2] = NULL;
	ft_unset(data, argument);
}

void	update_env_last_command(char *path, t_data *data)
{
	char	*new_var;

	if (path != NULL)
	{
		new_var = ft_strjoin("_=", path);
		export_variable("_", new_var, data);
		return ;
	}
}

int	is_this_var_env(char *str_env, char *new_var, size_t len)
{
	size_t	i;

	i = 0;
	if (!str_env || !new_var)
		return (0);
	while (str_env[i] && i < len)
	{
		if (str_env[i] != new_var[i])
			return (0);
		i++;
	}
	if (str_env[i] == '\0' || str_env[i] == '\n' || str_env[i] == '=')
		return (1);
	return (0);
}

int	is_var_env(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_isdigit(str[i]))
		return (0);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	if (str[i] == '\0' || str[i] == '\n' || str[i] == '=')
		return (1);
	return (0);
}

char	*get_val_env(char *var_name, t_data *data, size_t i, size_t j)
{
	size_t	len;
	char	*val_env;

	val_env = NULL;
	len = ft_strlen(var_name);
	while (data->envp[i])
	{
		if (is_this_var_env(data->envp[i], var_name, len))
			break ;
		i++;
	}
	if (data->envp[i])
	{
		while (data->envp[i][j] && data->envp[i][j] != '=')
			j++;
		if (data->envp[i][j] == '=')
		{
			val_env = ft_strdup(&data->envp[i][j + 1]);
			if (!val_env)
				exit_err("ft_strdup", data);
		}
	}
	return (val_env);
}
