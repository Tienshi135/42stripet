/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:46:25 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/13 11:26:51 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/builtins.h"
#include "../../header/environ.h"
#include "../../header/errors.h"

static int	new_tab_env(int i, char *new_var, t_data *data)
{
	char	**new_envtab;

	new_envtab = malloc(sizeof(char *) * (i + 2));
	if (!new_envtab)
		return (1);
	new_envtab[i + 1] = NULL;
	new_envtab[i] = ft_strdup(new_var);
	if (!new_envtab[i])
		return (1);
	while (i > 0)
	{
		i--;
		new_envtab[i] = ft_strdup(data->envp[i]);
		if (!new_envtab[i])
			return (1);
	}
	free_tab(data->envp);
	data->envp = new_envtab;
	return (0);
}

static int	add_variable_name(char *variable, t_data *data)
{
	char	*new_var;
	int		i;
	int		len;
	int		ret;

	i = 0;
	ret = 0;
	len = ft_strlen(variable);
	while (data->envp[i])
	{
		if (is_this_var_env(data->envp[i], variable, len) == 1)
			return (0);
		i++;
	}
	new_var = malloc(sizeof(char) * (len + 1));
	if (!new_var)
		return (-1);
	ft_strlcpy(new_var, variable, (size_t)len + 1);
	ret = new_tab_env(i, new_var, data);
	free(new_var);
	return (ret);
}

int	export_variable(char *var_name, char *new_var, t_data *data)
{
	int		i;
	size_t	len_var;

	i = 0;
	len_var = ft_strlen(var_name);
	while (data->envp[i])
	{
		if (is_this_var_env(data->envp[i], var_name, len_var) == 1)
		{
			free(data->envp[i]);
			data->envp[i] = new_var;
			return (0);
		}
		i++;
	}
	return (new_tab_env(i, new_var, data));
}

static int	look_variable(t_data *data, char *variable)
{
	char	*var_name;
	char	*new_var;
	char	*sign_equal;

	sign_equal = ft_strchr(variable, '=');
	var_name = variable;
	new_var = NULL;
	if (sign_equal)
	{
		new_var = ft_strdup(variable);
		if (!new_var)
			return (-1);
		*sign_equal = '\0';
		return (export_variable(var_name, new_var, data));
	}
	else
		return (add_variable_name(variable, data));
}

int	ft_export(t_data *data, char **arguments)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	while (arguments[i] && i < 2)
		i++;
	if (i == 1)
		return (display_env_var(data));
	i = 0;
	while (arguments[++i])
	{
		ret = is_var_env(arguments[i]);
		if (ret != 1)
		{
			err_mess_export(arguments[i]);
			data->return_v = 1;
		}
		else
			ret = look_variable(data, arguments[i]);
		if (data->return_v == 0)
			data->return_v = ret;
	}
	return (data->return_v);
}
