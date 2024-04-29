/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:07:21 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/29 13:26:01 by stripet          ###   ########.fr       */
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
	temp = ps_lstlast(*b);
	if (ps_lstsize(*b) == 1)
		*b = NULL;
	if (temp->previous)
	{
		temp->previous->next = NULL;
		temp->previous = NULL;
	}
	ps_lstadd_back(a, temp);
	ft_printf("pa\n");
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
	temp = ps_lstlast(*a);
	if (ps_lstsize(*a) == 1)
		*a = NULL;
	if (temp->previous)
	{
		temp->previous->next = NULL;
		temp->previous = NULL;
	}
	ps_lstadd_back(b, temp);
	ft_printf("pb\n");
	return (0);
}
