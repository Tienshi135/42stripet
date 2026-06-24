/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:40:35 by marcgodel         #+#    #+#             */
/*   Updated: 2024/11/29 14:30:26 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../header/utils.h"
#include <stdio.h>

static void	display_now(char *str)
{
	char	*sign_egal;

	printf("declar -x ");
	sign_egal = ft_strchr(str, '=');
	if (!sign_egal)
	{
		printf("%s\n", str);
		return ;
	}
	else
	{
		*sign_egal = '\0';
		printf("%s=\"%s\"\n", str, &sign_egal[1]);
		*sign_egal = '=';
	}
}

static void	display_env_var_sorted(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		display_now(tab[i]);
		i++;
	}
}

static int	cpy_tab(t_data *data, size_t *count, char ***new)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (data->envp[i])
		i++;
	*count = i;
	*new = malloc(sizeof(char *) * (i + 1));
	if (!new)
		return (-1);
	(*new)[i] = NULL;
	while (j < i)
	{
		len = ft_strlen(data->envp[j]);
		(*new)[j] = malloc(sizeof(char) * len + 1);
		if (!(*new)[j])
			return (-1);
		ft_strlcpy((*new)[j], data->envp[j], len + 1);
		j++;
	}
	return (0);
}

static void	bubble_sorte_tab(char **new, size_t count)
{
	size_t	i;
	int		move;
	char	*temp;

	while (1)
	{
		i = 0;
		move = 0;
		while (i < count - 1)
		{
			if (string_cmp(new[i], new[i + 1]) <= 0)
				i++;
			else
			{
				temp = new[i];
				new[i] = new[i + 1];
				new[i + 1] = temp;
				i++;
				move = 1;
			}
		}
		if (move == 0)
			break ;
	}
}

int	display_env_var(t_data *data)
{
	char	**new;
	size_t	count;
	int		ret;

	ret = cpy_tab(data, &count, &new);
	if (ret != 0)
		return (ret);
	bubble_sorte_tab(new, count);
	display_env_var_sorted(new);
	free_tab(new);
	return (0);
}
