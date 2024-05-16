/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:41:01 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/16 13:36:31 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rotate.h"
#include "../includes/utils.h"

/// @brief Shift up all elements of stack a by 1.
/// The first element becomes the last one.
/// @param t_stack a 
/// @return 1 on success -1 on failure
int	ra(t_stack **a, int print)
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
	if (print == true)
		ft_printf("ra\n");
	return (0);
}

/// @brief Shift up all elements of stack b by 1.
/// The first element becomes the last one.
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	rb(t_stack **b, int print)
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
	if (print == true)
		ft_printf("rb\n");
	return (0);
}

/// @brief Shift up all elements of stack a && b by 1.
/// The first element becomes the last one.
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	rr(t_stack **a, t_stack **b, int print)
{
	if ((ra (&(*a), false) == -1) || ((rb (&(*b), false)) == -1))
		return (-1);
	if (print == true)
		ft_printf("rr\n");
	return (1);
}

void	rotate_both(t_data *data, t_stack *to_do)
{
	while (to_do->cost_a > 0 && to_do->cost_b > 0)
	{
		rr(&(data->a), &(data->b), true);
		to_do->cost_a--;
		to_do->cost_b--;
	}
}
