/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:49:50 by stripet           #+#    #+#             */
/*   Updated: 2024/07/24 11:18:42 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parse.h"
#include "../header/utils.h"

void	get_status(t_status *status, char c)
{
	if (c == '\"')
	{
		if (*status == DOUBLE_QUOTED)
			*status = UNQUOTED;
		else if (*status == SINGLE_QUOTED)
			*status = SINGLE_QUOTED;
		else
			*status = DOUBLE_QUOTED;
	}
	else if (c == '\'')
	{
		if (*status == SINGLE_QUOTED)
			*status = UNQUOTED;
		else if (*status == DOUBLE_QUOTED)
			*status = DOUBLE_QUOTED;
		else
			*status = SINGLE_QUOTED;
	}
}
