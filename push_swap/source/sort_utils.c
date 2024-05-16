/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:59:43 by stripet           #+#    #+#             */
/*   Updated: 2024/05/16 14:43:06 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort_utils.h"
#include "../includes/utils.h"
#include "../includes/math.h"
#include "../includes/algorythm.h"

void	sort_3(t_stack **stack)
{
	t_stack	*nodes[3];

	while (!is_sorted(*stack))
	{
		nodes[0] = ps_lstlast(*stack);
		nodes[1] = nodes[0]->previous;
		nodes[2] = *stack;
		if (nodes[0]->content > nodes[2]->content)
		{
			ra(stack, true);
			sa(stack, true);
		}
		else if (nodes[0]->content > nodes[1]->content)
			sa(stack, true);
		else if (nodes[1]->content > nodes[2]->content)
		{
			rra(stack, true);
			sa(stack, true);
		}
	}
}

void	sort_small_stack(t_data *data)
{
	if (is_sorted(data->a))
		return ;
	if (ps_lstsize(data->a) == 2 && !is_sorted(data->a))
		sa(&(data->a), true);
	else if (ps_lstsize(data->a) == 3)
		sort_3(&(data->a));
	else if (ps_lstsize(data->a) == 4)
	{
		pb(&(data->a), &(data->b), true);
		sort_3(&(data->a));
	}
}

void	shift_stack(t_data *data)
{
	t_stack	*lowest;
	int		size;

	lowest = find_smallest(data->a);
	size = ps_lstsize(data->a);
	if (lowest->position > size / 2)
	{
		while (ps_lstlast(data->a) != lowest)
			rra(&data->a, true);
	}
	else
		while (ps_lstlast(data->a) != lowest)
			ra(&data->a, true);
}
