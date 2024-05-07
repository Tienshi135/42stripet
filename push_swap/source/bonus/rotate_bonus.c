/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:18:29 by stripet           #+#    #+#             */
/*   Updated: 2024/05/06 11:19:58 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/rotate_bonus.h"
#include "../../includes/utils.h"

/// @brief Shift up all elements of stack a by 1.
/// The first element becomes the last one.
/// @param t_stack a 
/// @return 1 on success -1 on failure
int	ra_bonus(t_stack **a)
{
	t_stack	*temp;
	t_stack	*cursor;

	if (ps_lstsize(*a) < 2)
		return (-1);
	temp = ps_lstlast(*a);
	cursor = *a;
	temp->previous->next = NULL;
	temp->previous = NULL;
	temp->next = cursor;
	cursor->previous = temp;
	*a = temp;
	return (0);
}

/// @brief Shift up all elements of stack b by 1.
/// The first element becomes the last one.
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	rb_bonus(t_stack **b)
{
	t_stack	*temp;
	t_stack	*cursor;

	if (ps_lstsize(*b) < 2)
		return (-1);
	temp = ps_lstlast(*b);
	cursor = *b;
	temp->previous->next = NULL;
	temp->previous = NULL;
	temp->next = cursor;
	cursor->previous = temp;
	*b = temp;
	return (0);
}

/// @brief Shift up all elements of stack a && b by 1.
/// The first element becomes the last one.
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	rr_bonus(t_stack **a, t_stack **b)
{
	if ((ra_bonus (&(*a)) == -1) || ((rb_bonus (&(*b))) == -1))
		return (-1);
	return (1);
}
