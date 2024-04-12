/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:39:15 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/10 16:20:29 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	data_cleanup(t_data data)
{
	if (data.a)
		ps_lst_free(data.a);
	if (data.b)
		ps_lst_free(data.b);
}

int	ps_lstsize(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ps_lst_free(t_stack *tofree)
{
	t_stack	*cursor;

	cursor = tofree;
	while (cursor)
	{
		free(cursor);
		cursor = tofree->next;
		tofree = cursor;
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
