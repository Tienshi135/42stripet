/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:39:15 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/10 14:45:28 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../includes/math.h"

void	data_cleanup(t_data *data)
{
	if (data->a)
		ps_lst_free(data->a);
	if (data->b)
		ps_lst_free(data->b);
}

void	ps_lst_free(t_stack *tofree)
{
	t_stack	*cursor;
	t_stack	*freeable;

	cursor = tofree;
	while (cursor)
	{
		freeable = cursor;
		cursor = cursor->next;
		free(freeable);
	}
}

int	is_valid(t_data *data, char *str)
{
	t_stack	*cursor;

	cursor = data->a;
	if (!ft_isint(str))
		return (0);
	while (cursor)
	{
		if (cursor->content == ft_atoi(str))
			return (0);
		cursor = cursor->next;
	}
	return (1);
}
