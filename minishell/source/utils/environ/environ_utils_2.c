/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:11:36 by marcgodel         #+#    #+#             */
/*   Updated: 2025/02/03 13:34:20 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../header/utils.h"
#include "../../../header/environ.h"
#include <stdio.h>

static void	create_shlvl(int i, char *new_var, t_data *data)
{
	char	**new_envtab;

	new_envtab = malloc(sizeof(char *) * (i + 2));
	if (!new_envtab)
	{
		perror("malloc");
		exit(1);
	}
	new_envtab[i + 1] = NULL;
	new_envtab[i] = ft_strdup(new_var);
	while (i > 0)
	{
		i--;
		new_envtab[i] = ft_strdup(data->envp[i]);
	}
	free_tab(data->envp);
	data->envp = new_envtab;
}

static void	update_shlvl(int i, t_data *data)
{
	int		j;
	int		number;
	char	*new_num;
	char	*new_value;

	j = 0;
	while (data->envp[i][j] && data->envp[i][j] != '=')
		j++;
	if (data->envp[i][j] == '=')
	{
		number = ft_atoi(&(data->envp[i][j + 1])) + 1;
		new_num = ft_itoa(number);
		new_value = ft_strjoin("SHLVL=", new_num);
		free(new_num);
	}
	else
		new_value = ft_strdup("SHLVL=1");
	free(data->envp[i]);
	data->envp[i] = new_value;
}

void	look_shlvl(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (is_this_var_env(data->envp[i], "SHLVL", 5) == 1)
		{
			update_shlvl(i, data);
			return ;
		}
		i++;
	}
	create_shlvl(i, "SHLVL=1", data);
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
