/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:07:21 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/05 11:15:33 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push.h"
#include "../includes/utils.h"


/// @brief Take the first element at the top of b and put it at the top of a.
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*b))
		return (-1);
	temp = *b;
	temp->next->previous = NULL;
	*b = (*b)->next;
	temp->next = *a;
	temp->previous = NULL;
	(*a)->previous = temp;
	*a = temp;
	return (0);
}

/// @brief Take the first element at the top of a and put it at the top of b.
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*a))
		return (-1);
	temp = *a;
	temp->next->previous = NULL;
	*a = (*a)->next;
	temp->next = *b;
	temp->previous = NULL;
	(*b)->previous = temp;
	*b = temp;
	return (0);
}
