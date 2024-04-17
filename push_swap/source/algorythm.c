/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:12:00 by stripet           #+#    #+#             */
/*   Updated: 2024/04/17 14:25:21 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algorythm.h"
#include "../includes/push_swap.h"

static int	calculate_moves_to_top(t_data *data, t_stack *elem)
{
	t_stack	*cursor;
	int		result[2];

	result[0] = 1;
	result[1] = 1;
	cursor = elem;
	if (cursor->next == ps_lstlast(data->a))
		return (result[0]);
	if (cursor == ps_lstlast(data->a))
		return (0);
	while (cursor)
	{
		result[0]++;
		cursor = cursor->next;
	}
	cursor = elem;
	while (cursor)
	{
		result[1]++;
		cursor = cursor->previous;
	}
	if (result[0] < result[1])
		return (result[0]);
	elem->left = 1;
	return (result[1]);
}

static void	get_to_top(t_data *data, t_stack *current)
{
	if (current->next == ps_lstlast(data->a))
	{
		sa(&(data->a));
		return ;
	}
	else if (current->left == 1)
	{
		while (current->moves > 0)
		{
			rra(&(data->a));
			current->moves--;
		}
	}
	else
	{
		while (current->moves > 0)
		{
			ra(&(data->a));
			current->moves--;
		}
	}
}

static void	exec_lowest_moves_to_top(t_data *data, int mid)
{
	t_stack	*cursor;
	int		lowest;
	t_stack	*to_do;

	cursor = ps_lstlast(data->a);
	lowest = 7;
	while (cursor)
	{
		if (cursor->index < mid)
		{
			if (cursor->moves <= lowest)
			{
				lowest = cursor->moves;
				to_do = cursor;
			}
		}
		cursor = cursor->previous;
	}
	if (to_do->moves != 0)
		get_to_top(data, to_do);
	pb(&(data->a), &(data->b));
}

static void	prepare_stacks(t_data *data)
{
	int		mid;
	t_stack	*cursor;

	mid = data->a->size / 2;
	data->a->size -= mid;
	while (ps_lstsize(data->b) != mid)
	{
		cursor = ps_lstlast(data->a);
		while (cursor)
		{
			if (cursor->index < mid)
				cursor->moves = calculate_moves_to_top(data, cursor);
			cursor = cursor->previous;
		}
		ft_printf("Before everything\n");
		print_list(data);
		exec_lowest_moves_to_top(data, mid);
		ft_printf("after swap\n");
		print_list(data);
	}
}

void	move_set(t_data *data)
{
	prepare_stacks(data);
}
