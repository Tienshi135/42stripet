/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:39:05 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/15 14:45:11 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/builtins.h"
#include "../../header/errors.h"
#include "../../header/environ.h"

static int	oldpwd_without_value(t_data *data)
{
	char	*old_pwd;

	old_pwd = ft_strdup("OLDPWD");
	if (!old_pwd)
		exit_err("malloc", data);
	if (export_variable("OLDPWD", old_pwd, data) == -1)
		exit_err("malloc", data);
	return (0);
}

static int	is_this_in_env(char *varname, char **envp)
{
	size_t	i;
	size_t	len;
	int		ret;

	len = ft_strlen(varname);
	i = 0;
	ret = 0;
	while (envp[i])
	{
		ret = is_this_var_env(envp[i], varname, len);
		if (ret == 1)
			return (1);
		i++;
	}
	return (0);
}

static int	update_pwd(t_data *data)
{
	char	*buffer;
	char	*pwd;

	if (is_this_in_env("PWD", data->envp))
	{
		buffer = getcwd(NULL, 0);
		if (!buffer)
			exit_err("getcwd", data);
		pwd = ft_strjoin("PWD=", buffer);
		free(buffer);
		if (export_variable("PWD", pwd, data) == -1)
			exit_err("malloc", data);
	}
	return (0);
}

static int	update_oldpwd(t_data *data)
{
	char	*buffer;
	char	*old_pwd;

	if (is_this_in_env("OLDPWD", data->envp))
	{
		buffer = get_val_env("PWD", data);
		if (buffer)
		{
			old_pwd = ft_strjoin("OLDPWD=", buffer);
			free(buffer);
			if (!old_pwd)
				exit_err("malloc", data);
			if (export_variable("OLDPWD", old_pwd, data) == -1)
				exit_err("malloc", data);
		}
		else
			oldpwd_without_value(data);
	}
	update_pwd(data);
	return (0);
}

int	ft_cd(char **arguments, t_data *data)
{
	char	*home_path;

	if (arguments[1] && arguments[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	if (!arguments[1] || ft_strncmp(arguments[1], "~", 2) == 0
		|| ft_strncmp(arguments[1], "--", 3) == 0)
	{
		home_path = getenv("HOME");
		if (!home_path)
		{
			ft_putstr_fd("bash: cd: HOME not set\n", 1);
			return (1);
		}
		if (chdir(home_path) == 0)
			return (update_oldpwd(data));
	}
	if (chdir(arguments[1]) == 0)
		return (update_oldpwd(data));
	ft_printf("minishell: cd: %s: No such file or directory\n");
	return (1);
}
