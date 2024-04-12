/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:24:57 by stripet           #+#    #+#             */
/*   Updated: 2024/04/12 15:23:45 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/math.h"
#include "../includes/list_utils.h"
#include "../includes/utils.h"

int	ps_average(t_stack *stack)
{
	int		result;
	t_stack	*cursor;

	cursor = stack;
	result = 0;
	while (cursor)
	{
		result += cursor->content;
		cursor = cursor->next;
	}
	return (result / ps_lstsize(stack));
}

int	ps_max(t_stack *stack)
{
	int		result;
	t_stack	*cursor;

	cursor = stack;
	result = 0;
	while (cursor)
	{
		if (cursor->content > result)
			result = cursor->content;
		cursor = cursor->next;
	}
	return (result);
}

int	ps_min(t_stack *stack)
{
	int		result;
	t_stack	*cursor;

	cursor = stack;
	result = 0;
	while (cursor)
	{
		if (cursor->content < result)
			result = cursor->content;
		cursor = cursor->next;
	}
	return (result);
}

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
