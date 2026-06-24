/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:24:27 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/11 20:32:35 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/builtins.h"
#include "../../header/environ.h"
#include "../../header/errors.h"

void	clean_var_env(t_data *data, size_t i)
{
	char	**new_tab_env;
	size_t	size_tab;
	size_t	j;

	size_tab = 0;
	j = 0;
	while (data->envp[size_tab])
		size_tab++;
	new_tab_env = malloc(sizeof(char *) * (size_tab));
	if (!new_tab_env)
		exit_err("malloc", data);
	while (j != i)
	{
		new_tab_env[j] = ft_strdup(data->envp[j]);
		j++;
	}
	while (j != size_tab)
	{
		new_tab_env[j] = ft_strdup(data->envp[j + 1]);
		j++;
	}
	new_tab_env[size_tab - 1] = NULL;
	free_tab(data->envp);
	data->envp = new_tab_env;
}

int	ft_unset(t_data *data, char **arguments)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (arguments[j])
	{
		len = ft_strlen(arguments[j]);
		while (data->envp[i])
		{
			if (is_this_var_env(data->envp[i], arguments[j], len) == 1)
			{
				clean_var_env(data, i);
				break ;
			}
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}
