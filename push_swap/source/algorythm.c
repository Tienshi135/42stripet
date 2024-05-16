/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:15:43 by stripet           #+#    #+#             */
/*   Updated: 2024/05/16 13:37:43 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algorythm.h"
#include "../includes/utils.h"
#include "../includes/math.h"

void	set_target_position(t_data *data)
{
	t_stack	*cursor_b;

	cursor_b = ps_lstlast(data->b);
	set_position(data->a);
	set_position(data->b);
	while (cursor_b)
	{
		cursor_b->target_position = set_target(data, cursor_b->index);
		cursor_b = cursor_b->previous;
	}
}

void	do_move(t_data *data, t_stack *to_do)
{
	if (to_do->cost_a > 0 && to_do->cost_b > 0)
		rotate_both(data, to_do);
	else if (to_do->cost_a < 0 && to_do->cost_b < 0)
		reverse_rotate_both(data, to_do);
	do_costa(data, to_do);
	do_costb(data, to_do);
	pa(&(data->a), &(data->b), true);
}

void	execute_cheapest(t_data *data)
{
	t_stack	*cursor;
	t_stack	*cheapest;

	if (ps_lstsize(data->b) == 0)
		return ;
	if (ps_lstsize(data->b) == 1)
		do_move(data, data->b);
	else
	{
		cursor = data->b;
		cheapest = cursor->next;
		while (cursor)
		{
			if (ft_abs(cursor->cost_a) + ft_abs(cursor->cost_b)
				< ft_abs(cheapest->cost_a + cheapest->cost_b))
				cheapest = cursor;
			cursor = cursor->next;
		}
		do_move(data, cheapest);
	}
}

void	push_to_a(t_data *data)
{
	while (ps_lstsize(data->b) > 0)
	{
		set_target_position(data);
		get_cost(data);
		execute_cheapest(data);
	}
}

void	push_to_b(t_data *data)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ps_lstsize(data->a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((data->a)->index <= stack_size / 2)
		{
			pb(&(data->a), &(data->b), true);
			pushed++;
		}
		else
			ra(&(data->a), true);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(&(data->a), &(data->b), true);
		pushed++;
	}
}
