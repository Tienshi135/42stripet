/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:11:21 by marcgodel         #+#    #+#             */
/*   Updated: 2025/01/06 17:16:24 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/builtins.h"
#include <stdio.h>

static int	print_args(char **arguments, int i)
{
	int	first_printed;

	first_printed = 0;
	while (arguments[i])
	{
		if (arguments[i] && arguments[i][0] != 0)
		{
			if (printf("%s", arguments[i]) < 0)
				return (1);
			first_printed = 1;
		}
		i++;
		if (arguments[i] && first_printed == 1)
		{
			if (printf(" ") < 0)
				return (1);
		}
	}
	return (0);
}

int	ft_echo(char **arguments)
{
	int	i;

	i = 1;
	if (ft_strncmp(arguments[i], "-n", 3) == 0)
		i++;
	if (print_args(arguments, i))
		return (1);
	if (ft_strncmp(arguments[1], "-n", 3) != 0)
	{
		if (printf("\n") < 0)
			return (1);
	}
	return (0);
}
