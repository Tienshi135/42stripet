/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:24:44 by stripet           #+#    #+#             */
/*   Updated: 2023/10/30 13:00:48 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversationfunctions.h"

static int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

int	printstring(char *str)
{
	int	returnvalue;

	returnvalue = str_len(str);
	if (!str)
	{
		str = "(null)";
		returnvalue = 6;
	}
	ft_putstr_fd(str, 1);
	return (returnvalue);
}
