/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:12:05 by stripet           #+#    #+#             */
/*   Updated: 2024/05/06 11:18:15 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/push_bonus.h"
#include "../../includes/utils.h"

/// @brief Take the first element at the top of b and put it at the top of a.
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	pa_bonus(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*b))
		return (-1);
	temp = ps_lstlast(*b);
	if (ps_lstsize(*b) == 1)
		*b = NULL;
	if (temp->previous)
	{
		temp->previous->next = NULL;
		temp->previous = NULL;
	}
	ps_lstadd_back(a, temp);
	return (0);
}

/// @brief Take the first element at the top of a and put it at the top of b.
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	pb_bonus(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*a))
		return (-1);
	temp = ps_lstlast(*a);
	if (ps_lstsize(*a) == 1)
		*a = NULL;
	if (temp->previous)
	{
		temp->previous->next = NULL;
		temp->previous = NULL;
	}
	ps_lstadd_back(b, temp);
	return (0);
}
