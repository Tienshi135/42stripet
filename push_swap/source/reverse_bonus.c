/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:15:00 by stripet           #+#    #+#             */
/*   Updated: 2024/05/06 11:17:24 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reverse_bonus.h"
#include "../includes/utils.h"

/// @brief Shift down all elements of stack a by 1.
/// The last element becomes the first one.
/// @param t_stack a
/// @return 1 on success -1 on failure
int	rra_bonus(t_stack **a)
{
	t_stack	*temp;
	t_stack	*cursor;

	if (ps_lstsize(*a) < 2)
		return (-1);
	temp = *a;
	cursor = ps_lstlast(*a);
	cursor->next = temp;
	*a = temp->next;
	(*a)->previous = NULL;
	temp->previous = cursor;
	temp->next = NULL;
	return (0);
}

/// @brief Shift down all elements of stack b by 1.
/// The last element becomes the first one.
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	rrb_bonus(t_stack **b)
{
	t_stack	*temp;
	t_stack	*cursor;

	if (ps_lstsize(*b) < 2)
		return (-1);
	temp = *b;
	cursor = ps_lstlast(*b);
	cursor->next = temp;
	*b = temp->next;
	(*b)->previous = NULL;
	temp->previous = cursor;
	temp->next = NULL;
	return (0);
}

/// @brief Shift down all elements of stack a && b by 1.
/// The last element becomes the first one.
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	rrr_bonus(t_stack **a, t_stack **b)
{
	if ((rra_bonus (&(*a)) == -1) || ((rrb_bonus (&(*b))) == -1))
		return (-1);
	return (1);
}
