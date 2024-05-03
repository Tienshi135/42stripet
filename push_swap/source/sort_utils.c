/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:59:43 by stripet           #+#    #+#             */
/*   Updated: 2024/05/03 16:04:20 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort_utils.h"

void	sort_3(t_stack **stack)
{
	t_stack	*nodes[3];

	nodes[0] = ps_lstlast(*stack);
	nodes[1] = nodes[0]->previous;
	nodes[2] = *stack;
	while (!is_sorted(*stack))
	{
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
