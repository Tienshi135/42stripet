/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:15:43 by stripet           #+#    #+#             */
/*   Updated: 2024/05/06 17:45:06 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algorythm.h"
#include "../includes/utils.h"
#include "../includes/math.h"

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
		add_to_moves(&(element->movesA), "rb ", &result);
		cursor = cursor->previous;
		counter++;
	}
	add_to_moves(&(element->movesA), "pb ", &result);
	while (counter > 0)
	{
		add_to_moves(&(element->movesA), "rrb ", &result);
		counter--;
	}
	return (result);
}

static int	moves_to_b(t_data *data, t_stack *element)
{
	int		steps;

    steps = 0;
    steps += get_to_top(element);
	if (element->content > data->smallest
		&& element->content < data->biggest)
		steps += arrange_middle(data, element);
	else
	{
		add_to_moves(&(element->movesA), "pb ", &steps);
		if (element->content < data->smallest)
			add_to_moves(&(element->movesA), "rb ", &steps);
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
	if (!is_rsorted(data->b) && ps_lstsize(data->b) == 2)
		rb(&(data->b));
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

void	stackA_check(t_data *data)
{
	t_stack	*cursorA;
	t_stack	*cursorB;

    cursorA = data->a;
    cursorB = ps_lstlast(data->b);
    if (cursorB->content > ps_lstlast(data->a)->content)
        while (cursorB->content > ps_lstlast(data->a)->content
            && ps_lstlast(data->a) != cursorA)
            ra(&(data->a));
    else if (cursorA > cursorB && cursorA < ps_lstlast(data->a))
        rra(&(data->a));
}

void	push_to_a(t_data *data)
{
	while (ps_lstsize(data->b) > 0)
	{
        stackA_check(data);
		pa(&(data->a), &(data->b));
	}
    if (!is_sorted(data->a))
    {
        while (data->a->content < ps_lstlast(data->a)->content)
            rra(&(data->a));
    }
}
