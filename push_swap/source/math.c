/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:24:57 by stripet           #+#    #+#             */
/*   Updated: 2024/05/10 14:46:22 by stripet          ###   ########.fr       */
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
