/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:41:22 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/05 10:12:41 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

/// @brief Swap the first 2 elements at the top of stack a
/// @param t_stack a 
/// @return 1 on success -1 on failure
int	sa(t_stack **a)
{
	t_stack	*temp;

	if (ps_lstsize(*a) < 2)
		return (-1);
	temp = (*a)->next;
	if (temp->next)
	{
		temp->next->previous = *a;
		(*a)->next = temp->next;
	}
	else
		(*a)->next = NULL;
	(*a)->previous = temp;
	temp->next = *a;
	temp->previous = NULL;
	*a = temp;
	return (1);
}

/// @brief Swap the first 2 elements at the top of stack b
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	sb(t_stack **b)
{
	t_stack	*temp;

	if (ps_lstsize(*b) < 2)
		return (-1);
	temp = (*b)->next;
	if (temp->next)
	{
		temp->next->previous = *b;
		(*b)->next = temp->next;
	}
	else
		(*b)->next = NULL;
	(*b)->previous = temp;
	temp->next = *b;
	temp->previous = NULL;
	*b = temp;
	return (1);
}

/// @brief Swap the first 2 elements at the top of stack a && b
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	ss(t_stack **a, t_stack **b)
{
	if ((sa (&(*a)) == -1) || ((sb (&(*b))) == -1))
		return (-1);
	return (1);
}
