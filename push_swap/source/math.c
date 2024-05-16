/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:24:57 by stripet           #+#    #+#             */
/*   Updated: 2024/05/16 13:09:50 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/math.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*cursor;

	cursor = ps_lstlast(stack);
	while (cursor->previous)
	{
		if (cursor->previous->content < cursor->content)
			return (0);
		cursor = cursor->previous;
	}
	return (1);
}

int	is_rsorted(t_stack *stack)
{
	t_stack	*cursor;

	cursor = ps_lstlast(stack);
	while (cursor->previous)
	{
		if (cursor->previous->content > cursor->content)
			return (0);
		cursor = cursor->previous;
	}
	return (1);
}

t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*cursor;
	t_stack	*biggest;

	cursor = stack;
	biggest = cursor;
	while (cursor)
	{
		if (cursor->content > biggest->content)
			biggest = cursor;
		cursor = cursor->next;
	}
	return (biggest);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*cursor;
	t_stack	*smallest;

	cursor = stack;
	smallest = cursor;
	while (cursor)
	{
		if (cursor->content < smallest->content)
			smallest = cursor;
		cursor = cursor->next;
	}
	return (smallest);
}

void	get_cost(t_data *data)
{
	t_stack	*cursor_b;
	int		size_a;
	int		size_b;

	cursor_b = ps_lstlast(data->b);
	size_a = ps_lstsize(data->a);
	size_b = ps_lstsize(data->b);
	while (cursor_b)
	{
		cursor_b->cost_b = cursor_b->position;
		if (cursor_b->position > size_b / 2)
			cursor_b->cost_b = (size_b - cursor_b->position) * -1;
		cursor_b->cost_a = cursor_b->target_position;
		if (cursor_b->target_position > size_a / 2)
			cursor_b->cost_a = (size_a - cursor_b->target_position) * -1;
		cursor_b = cursor_b->previous;
	}
}
