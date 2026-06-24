/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:45:48 by marcgodel         #+#    #+#             */
/*   Updated: 2024/11/29 14:29:39 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/builtins.h"
#include <stdio.h>

int	ft_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (ft_strchr(data->envp[i], '='))
		{
			if (printf("%s\n", data->envp[i]) < 0)
				return (1);
		}
		i++;
	}
	return (0);
}
