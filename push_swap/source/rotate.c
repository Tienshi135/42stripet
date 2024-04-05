/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:41:01 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/05 11:00:39 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rotate.h"
#include "../includes/utils.h"

/// @brief Shift up all elements of stack a by 1.
/// The first element becomes the last one.
/// @param t_stack a 
/// @return 1 on success -1 on failure
int	ra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*cursor;

	if (ps_lstsize(*a) < 2)
		return (-1);
	temp = *a;
	cursor = ps_lstlast(*a);
	cursor->next = temp;
	temp->previous = cursor;
	*a = (*a)->next;
	(*a)->previous = NULL;
	temp->next = NULL;
	return (0);
}

/// @brief Shift up all elements of stack b by 1.
/// The first element becomes the last one.
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	rb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*cursor;

	if (ps_lstsize(*b) < 2)
		return (-1);
	temp = *b;
	cursor = ps_lstlast(*b);
	cursor->next = temp;
	temp->previous = cursor;
	*b = (*b)->next;
	(*b)->previous = NULL;
	temp->next = NULL;
	return (0);
}

/// @brief Shift up all elements of stack a && b by 1.
/// The first element becomes the last one.
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	rr(t_stack **a, t_stack **b)
{
	if ((ra (&(*a)) == -1) || ((rb (&(*b))) == -1))
		return (-1);
	return (1);
}
