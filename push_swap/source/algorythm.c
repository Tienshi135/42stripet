/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:15:43 by stripet           #+#    #+#             */
/*   Updated: 2024/05/13 14:23:39 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algorythm.h"
#include "../includes/utils.h"
#include "../includes/math.h"

static int	set_target(t_data *data, int index_b)
{
	t_stack	*cursor;
	t_stack	*smallest;

	cursor = data->a;
	smallest = find_biggest(data->a);
	while (cursor)
	{
		if (cursor->index > index_b && cursor->index < smallest->index)
			smallest = cursor;
		cursor = cursor->next;
	}
	return (smallest->index);
}

void	set_position(t_stack *stack)
{
	t_stack	*cursor;
	int		i;

	cursor = stack;
	i = 0;
	while (cursor)
	{
		cursor->position = i;
		cursor = cursor->next;
		i++;
	}
}

void	set_target_position(t_data *data)
{
	t_stack	*cursor_b;

	cursor_b = data->b;
	set_position(data->a);
	set_position(data->b);
	while (cursor_b)
	{
		cursor_b->target_position = set_target(data, cursor_b->index);
		cursor_b = cursor_b->next;
	}
}

void	get_cost(t_data *data)
{
	t_stack	*cursor_a;
	t_stack	*cursor_b;
	int		size_a;
	int		size_b;

	cursor_a = data->a;
	cursor_b = data->b;
	size_a = ps_lstsize(cursor_a);
	size_b = ps_lstsize(cursor_b);
	while (cursor_b)
	{
		cursor_b->cost_b = cursor_b->position;
		if (cursor_b->position > size_b / 2)
			cursor_b->cost_b = (size_b - cursor_b->position) * -1;
		cursor_b->cost_a = cursor_b->target_position;
		if (cursor_b->target_position > size_a / 2)
			cursor_b->cost_a = (size_a - cursor_b->target_position) * -1;
		cursor_b = cursor_b->next;
	}
}

void	reverse_rotate_both(t_data *data, t_stack *to_do)
{
	while (to_do->cost_a < 0 && to_do->cost_b < 0)
	{
		rrr(&(data->a), &(data->b));
		to_do->cost_a++;
		to_do->cost_b++;
	}
}

void	rotate_both(t_data *data, t_stack *to_do)
{
	while (to_do->cost_a > 0 && to_do->cost_b > 0)
	{
		rr(&(data->a), &(data->b));
		to_do->cost_a--;
		to_do->cost_b--;
	}
}

void	do_costb(t_data *data, t_stack *to_do)
{
	while (to_do->cost_b)
	{
		if (to_do->cost_b > 0)
		{
			rb(&(data->b));
			to_do->cost_b--;
		}
		else
		{
			rrb(&(data->b));
			to_do->cost_b++;
		}
	}
}

void	do_costa(t_data *data, t_stack *to_do)
{
	while (to_do->cost_a)
	{
		if (to_do->cost_a > 0)
		{
			ra(&(data->a));
			to_do->cost_a--;
		}
		else
		{
			rra(&(data->a));
			to_do->cost_a++;
		}
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
	pa(&(data->a), &(data->b));
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
			pb(&(data->a), &(data->b));
			pushed++;
		}
		else
			ra(&(data->a));
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(&(data->a), &(data->b));
		pushed++;
	}
}
