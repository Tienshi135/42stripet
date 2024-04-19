/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:12:00 by stripet           #+#    #+#             */
/*   Updated: 2024/04/19 10:56:53 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algorythm.h"
#include "../includes/push_swap.h"

static int	find_median(t_stack *a)
{
	t_stack	*cursor;

	cursor = ps_lstlast(a);
	while (cursor)
	{
		if (cursor->sort_index == ps_lstsize(a) / 2)
			return (cursor->content);
		cursor = cursor->previous;
	}
	return (0);
}

static int	moves_counter(t_stack *stack, t_stack *start, int end)
{
	char	*buffer;

	if (start->index == end)
		return (0);
}

void	prepare_stack(t_data *data)
{
	t_stack	*cursor;
	t_stack	*to_push;
	int		median;
	int		temp;

	median = find_median(data->a);
	temp = ps_lstsize(data->a) + 1;
	while (ps_lstsize(data->a) >= ps_lstsize(data->b) + 1)
	{
		cursor = ps_lstlast(data->a);
		while (cursor)
		{
			if (cursor->content <= median)
			{
				if (moves_counter(data->a, cursor, 0) < temp)
					to_push = cursor;
			}
			cursor = cursor->previous;
		}
		//push to_push to b
	}
}
