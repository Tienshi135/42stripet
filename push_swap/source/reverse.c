/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:09:08 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/05 11:05:47 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reverse.h"
#include "../includes/utils.h"

/// @brief Shift down all elements of stack a by 1.
/// The last element becomes the first one.
/// @param t_stack a
/// @return 1 on success -1 on failure
int	rra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*cursor;

	if (ps_lstsize(*a) < 2)
		return (-1);
	temp = *a;
	cursor = ps_lstlast(*a);
	cursor->previous->next = NULL;
	cursor->previous = NULL;
	cursor->next = temp;
	temp->previous = cursor;
	*a = cursor;
	return (0);
}

/// @brief Shift down all elements of stack b by 1.
/// The last element becomes the first one.
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	rrb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*cursor;

	if (ps_lstsize(*b) < 2)
		return (-1);
	temp = *b;
	cursor = ps_lstlast(*b);
	cursor->previous->next = NULL;
	cursor->previous = NULL;
	cursor->next = temp;
	temp->previous = cursor;
	*b = cursor;
	return (0);
}

/// @brief Shift down all elements of stack a && b by 1.
/// The last element becomes the first one.
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	rrr(t_stack **a, t_stack **b)
{
	if ((rra (&(*a)) == -1) || ((rrb (&(*b))) == -1))
		return (-1);
	return (1);
}
