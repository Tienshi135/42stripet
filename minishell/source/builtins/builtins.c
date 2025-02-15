/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:53:00 by stripet           #+#    #+#             */
/*   Updated: 2024/12/12 20:50:27 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/builtins.h"

int	is_builtin(char *str)
{
	if (ft_strncmp(str, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(str, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(str, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(str, "export", 7) == 0)
		return (1);
	if (ft_strncmp(str, "exit", 5) == 0)
		return (1);
	if (ft_strncmp(str, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(str, "env", 4) == 0)
		return (1);
	return (0);
}

int	do_builtin(t_data *data, char **argv)
{
	int		ret;

	ret = 0;
	if (ft_strncmp(argv[0], "pwd", 4) == 0)
		ret = ft_pwd(argv);
	else if (ft_strncmp(argv[0], "echo", 5) == 0)
		ret = ft_echo(argv);
	else if (ft_strncmp(argv[0], "cd", 3) == 0)
		ret = ft_cd(argv, data, NULL, NULL);
	else if (ft_strncmp(argv[0], "export", 7) == 0)
		ret = ft_export(data, argv);
	else if (ft_strncmp(argv[0], "exit", 5) == 0)
		ft_exit(data, argv);
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		ret = ft_unset(data, argv);
	else if (ft_strncmp(argv[0], "env", 4) == 0)
		ft_env(data);
	else
		return (2);
	data->return_v = ret;
	return (ret);
}
