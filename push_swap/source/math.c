/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:24:57 by stripet           #+#    #+#             */
/*   Updated: 2024/05/07 15:48:33 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/math.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*cursor;

	cursor = ps_lstlast(stack);
	while (cursor->previous)
	{
		if (cursor->previous->content < cursor->content)
			return (0);
		cursor = cursor->previous;
	}
	return (1);
}

int	is_rsorted(t_stack *stack)
{
	t_stack	*cursor;

	cursor = ps_lstlast(stack);
	while (cursor->previous)
	{
		if (cursor->previous->content > cursor->content)
			return (0);
		cursor = cursor->previous;
	}
	return (1);
}

int	is_smallest(t_stack *stack, int value)
{
	t_stack	*cursor;

	cursor = stack;
	while (cursor)
	{
		if (cursor->content < value)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}
