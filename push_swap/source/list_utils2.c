/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:46:12 by stripet           #+#    #+#             */
/*   Updated: 2024/05/16 13:28:19 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list_utils2.h"

void	set_position(t_stack *stack)
{
	t_stack	*cursor;
	int		i;

	cursor = ps_lstlast(stack);
	i = 0;
	while (cursor)
	{
		cursor->position = i;
		cursor = cursor->previous;
		i++;
	}
}

int	set_target(t_data *data, int index_b)
{
	t_stack	*cursor;
	t_stack	*smallest;
	int		temp;

	cursor = ps_lstlast(data->a);
	smallest = find_biggest(data->a);
	temp = INT_MAX;
	while (cursor)
	{
		if (cursor->index > index_b && cursor->index < temp)
		{
			smallest = cursor;
			temp = smallest->index;
		}
		cursor = cursor->previous;
	}
	if (temp == INT_MAX)
		return (smallest->position + 1);
	return (smallest->position);
}

void	do_costa(t_data *data, t_stack *to_do)
{
	while (to_do->cost_a)
	{
		if (to_do->cost_a > 0)
		{
			ra(&(data->a), true);
			to_do->cost_a--;
		}
		else
		{
			rra(&(data->a), true);
			to_do->cost_a++;
		}
	}
}

void	do_costb(t_data *data, t_stack *to_do)
{
	while (to_do->cost_b)
	{
		if (to_do->cost_b > 0)
		{
			rb(&(data->b), true);
			to_do->cost_b--;
		}
		else
		{
			rrb(&(data->b), true);
			to_do->cost_b++;
		}
	}
}
