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

static int	update_oldpwd(t_data *data, char **old_pwd)
{
	char	*buffer;

	if (is_this_in_env("OLDPWD", data->envp))
	{
		buffer = ft_strjoin("OLDPWD=", *old_pwd);
		free(*old_pwd);
		if (!buffer)
			exit_err("malloc", data);
		if (export_variable("OLDPWD", buffer, data) == -1)
			exit_err("malloc", data);
	}
	else
		free(*old_pwd);
	update_pwd(data);
	return (0);
}

static int	try_chdir_oldpwd(t_data *data, char *argument, char **old_pwd)
{
	char	*buff;

	buff = get_val_env("OLDPWD", data, 0, 0);
	if (!buff)
	{
		free(*old_pwd);
		return (err_mess("OLPDPWD is unset"));
	}
	else
	{
		if (chdir(buff) == 0)
			return (update_oldpwd(data, old_pwd));
	}
	free(*old_pwd);
	ft_putstr_fd("minishell: cd:", STDERR_FILENO);
	err_mess_2(argument, "No such file or directory");
	return (1);
}

int	ft_cd(char **arguments, t_data *data, char *buff, char *old_pwd)
{
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		exit_err("getcwd", data);
	if (arguments[1] && arguments[2])
	{
		free(old_pwd);
		return (err_mess("minishell: cd: too many arguments"));
	}
	if (!arguments[1] || ft_strncmp(arguments[1], "~", 2) == 0
		|| ft_strncmp(arguments[1], "--", 3) == 0)
	{
		buff = getenv("HOME");
		if (!buff)
			return (err_mess("bash: cd: HOME not set"));
		if (chdir(buff) == 0)
			return (update_oldpwd(data, &old_pwd));
	}
	if ((ft_strncmp(arguments[1], "-", 2)) == 0)
		return (try_chdir_oldpwd(data, arguments[1], &old_pwd));
	if (chdir(arguments[1]) == 0)
		return (update_oldpwd(data, &old_pwd));
	free(old_pwd);
	ft_putstr_fd("minishell: cd:", STDERR_FILENO);
	return (err_mess_2(arguments[1], "No such file or directory"));
}
