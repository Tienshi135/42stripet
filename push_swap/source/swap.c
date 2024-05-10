/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:41:22 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/10 14:33:12 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"
#include "../includes/utils.h"

/// @brief Swap the first 2 elements at the top of stack a
/// @param t_stack a 
/// @return 1 on success -1 on failure
int	sa(t_stack **a)
{
	t_stack	*temp;
	t_stack	*cursor;

	if (ps_lstsize(*a) < 2)
		return (-1);
	temp = ps_lstlast(*a);
	cursor = temp->previous;
	if (cursor->previous != NULL)
		cursor->previous->next = temp;
	temp->next = cursor;
	temp->previous = cursor->previous;
	cursor->previous = temp;
	cursor->next = NULL;
	ft_printf("sa\n");
	return (1);
}

/// @brief Swap the first 2 elements at the top of stack b
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	sb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*cursor;

	if (ps_lstsize(*b) < 2)
		return (-1);
	temp = ps_lstlast(*b);
	cursor = temp->previous;
	if (cursor->previous != NULL)
		cursor->previous->next = temp;
	temp->next = cursor;
	temp->previous = cursor->previous;
	cursor->previous = temp;
	cursor->next = NULL;
	ft_printf("sb\n");
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
	ft_printf("ss\n");
	return (1);
}
