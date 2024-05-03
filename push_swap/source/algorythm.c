/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:15:43 by stripet           #+#    #+#             */
/*   Updated: 2024/05/03 17:54:42 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algorythm.h"
#include "../includes/math.h"
#include "../includes/push_swap.h"
#include "../includes/utils.h"

static int	arrange_middle(t_data *data, t_stack *element)
{
	t_stack	*cursor;
	int		result;
	int		counter;

	result = 0;
	counter = 0;
	cursor = ps_lstlast(data->b);
	while (cursor && (element->content < cursor->content))
	{
		add_to_moves(&(element->moves), "rb ", &result);
		cursor = cursor->previous;
		counter++;
	}
	add_to_moves(&(element->moves), "pb ", &result);
	while (counter > 0)
	{
		add_to_moves(&(element->moves), "rrb ", &result);
		counter--;
	}
	return (result);
}

static int	moves_to_b(t_data *data, t_stack *element)
{
	int		steps;
	t_stack	*cursor;

	steps = 0;
	cursor = element;
	if (!is_rsorted(data->b) && ps_lstsize(data->b) == 2)
		add_to_moves(&(element->moves), "rb ", &steps);
	steps += get_to_top(element);
	if (element->content > data->smallest
		&& element->content < data->biggest)
		steps += arrange_middle(data, element);
	else
	{
		add_to_moves(&(element->moves), "pb ", &steps);
		if (element->content < data->smallest)
			add_to_moves(&(element->moves), "rb ", &steps);
	}
	return (steps);
}

void	push_to_b(t_data *data)
{
	t_stack	*to_push;
	t_stack	*cursor;

	pb(&(data->a), &(data->b));
	pb(&(data->a), &(data->b));
	init_big_small(data);
	while (ps_lstsize(data->a) > 3)
	{
		to_push = ps_lstlast(data->a);
		cursor = ps_lstlast(data->a)->previous;
		while (cursor)
		{
			set_big_small(data);
			reset_moves(data);
			if (moves_to_b(data, cursor) < moves_to_b(data, to_push))
				to_push = cursor;
			cursor = cursor->previous;
		}
		ex_moves(data, to_push);
	}
}

static void	insert_back(t_data *data)
{
	t_stack	*cursor;
	t_stack	*cursorb;

	cursor = data->a;
	cursorb = ps_lstlast(data->b);
	if (data->a->content < ps_lstlast(data->a)->content
		&& data->a->content > cursorb->content)
	{
		while (data->a->content < ps_lstlast(data->a)->content
			&& data->a->content > cursorb->content)
			rra(&(data->a));
	}
	else if (cursorb->content > ps_lstlast(data->a)->content
		&& data->a->content > cursorb->content)
	{
		while (cursorb->content > ps_lstlast(data->a)->content)
			ra(&(data->a));
	}
	else if (data->a->content < ps_lstlast(data->a)->content
		&& cursorb->content > ps_lstlast(data->a)->content)
	{
		while (data->a->content < ps_lstlast(data->a)->content)
			rra(&(data->a));
	}
}

void	push_to_a(t_data *data)
{
	while (ps_lstsize(data->b) > 0)
	{
		insert_back(data);
		pa(&(data->a), &(data->b));
	}
	while (data->a->content < ps_lstlast(data->a)->content)
		rra(&(data->a));
	while (ps_lstlast(data->a)->content > data->a->content)
		ra(&(data->a));
}
