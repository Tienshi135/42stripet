/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:15:43 by stripet           #+#    #+#             */
/*   Updated: 2024/05/07 16:05:50 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algorythm.h"
#include "../includes/utils.h"
#include "../includes/math.h"

#include "../includes/push_swap.h"

static int	arrange_b(t_data *data, t_stack *element)
{
	int		counter;

	counter = 0;
	if (is_smallest(data->dupb, element->content))
	{
		while (data->dupb->content > ps_lstlast(data->dupb)->content)
			add_to_moves(&(element->movesb), "rrb", &counter);
		add_to_moves(&(element->movesb), "rb", &counter);
	}
	else
	{
		while (data->dupb->content > element->content)
			add_to_moves(&(element->movesb), "rrb", &counter);
		while (data->dupb->content < element->content)
			add_to_moves(&(element->movesb), "rb", &counter);
	}
	return (counter);
}

static int	moves_to_b(t_data *data, t_stack *element)
{
	int		steps;

	steps = 0;
	print_list(data);
	steps += get_to_top(element);
	add_to_moves(&(element->movesa), "pb", &steps);
	steps += arrange_b(data, element);
	return (steps);
}

void	push_to_b(t_data *data)
{
	t_stack	*to_push;
	t_stack	*cursor;

	sort_init(data);
	while (ps_lstsize(data->a) > 3)
	{
		to_push = ps_lstlast(data->dupa);
		cursor = to_push->previous;
		while (cursor)
		{
			reset_moves(data);
			if (moves_to_b(data, cursor) < moves_to_b(data, to_push))
				to_push = cursor;
			cursor = cursor->previous;
		}
		ex_moves(data, to_push);
	}
}

void	push_to_a(t_data *data)
{
	if (ps_lstlast(data->a)->content > ps_lstlast(data->b)->content)
		while (data->b)
			pa(&(data->a), &(data->b));
	else if (data->a->content < data->b->content)
		while (data->b)
			pa(&(data->a), &(data->b));
	else
	{
		while (ps_lstsize(data->b) > 0)
		{
			while (data->a->content < ps_lstlast(data->a)->content
				&& data->a->content > ps_lstlast(data->b)->content)
				rra(&(data->a));
			pa(&(data->a), &(data->b));
		}
	}
	if (!is_sorted(data->a))
	{
		while (data->a->content < ps_lstlast(data->a)->content)
			rra(&(data->a));
	}
}
