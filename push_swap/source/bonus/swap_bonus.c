/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:20:27 by stripet           #+#    #+#             */
/*   Updated: 2024/05/06 11:21:24 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/swap_bonus.h"
#include "../../includes/utils.h"

/// @brief Swap the first 2 elements at the top of stack a
/// @param t_stack a 
/// @return 1 on success -1 on failure
int	sa_bonus(t_stack **a)
{
	t_stack	*temp;
	t_stack	*cursor;

	if (ps_lstsize(*a) < 2)
		return (-1);
	temp = ps_lstlast(*a);
	cursor = temp->previous;
	cursor->previous->next = temp;
	temp->next = cursor;
	temp->previous = cursor->previous;
	cursor->previous = temp;
	cursor->next = NULL;
	return (1);
}

/// @brief Swap the first 2 elements at the top of stack b
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	sb_bonus(t_stack **b)
{
	t_stack	*temp;
	t_stack	*cursor;

	if (ps_lstsize(*b) < 2)
		return (-1);
	temp = ps_lstlast(*b);
	cursor = temp->previous;
	cursor->previous->next = temp;
	temp->next = cursor;
	temp->previous = cursor->previous;
	cursor->previous = temp;
	cursor->next = NULL;
	return (1);
}

/// @brief Swap the first 2 elements at the top of stack a && b
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	ss_bonus(t_stack **a, t_stack **b)
{
	if ((sa_bonus (&(*a)) == -1) || ((sb_bonus (&(*b))) == -1))
		return (-1);
	return (1);
}
