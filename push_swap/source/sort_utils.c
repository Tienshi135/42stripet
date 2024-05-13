/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:59:43 by stripet           #+#    #+#             */
/*   Updated: 2024/05/13 12:23:37 by stripet          ###   ########.fr       */
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
			ra(stack);
			sa(stack);
		}
		else if (nodes[0]->content > nodes[1]->content)
			sa(stack);
		else if (nodes[1]->content > nodes[2]->content)
		{
			rra(stack);
			sa(stack);
		}
	}
}

void	sort_small_stack(t_data *data)
{
	if (ps_lstsize(data->a) == 2 && !is_sorted(data->a))
		sa(&(data->a));
	else if (ps_lstsize(data->a) == 3)
		sort_3(&(data->a));
	else if (ps_lstsize(data->a) == 4)
	{
		pb(&(data->a), &(data->b));
		sort_3(&(data->a));
	}
}
