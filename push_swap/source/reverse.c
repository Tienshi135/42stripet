/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:09:08 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/16 13:35:56 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reverse.h"
#include "../includes/utils.h"

/// @brief Shift down all elements of stack a by 1.
/// The last element becomes the first one.
/// @param t_stack a
/// @return 1 on success -1 on failure
int	rra(t_stack **a, int print)
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
	if (print == true)
		ft_printf("rra\n");
	return (0);
}

/// @brief Shift down all elements of stack b by 1.
/// The last element becomes the first one.
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	rrb(t_stack **b, int print)
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
	if (print == true)
		ft_printf("rrb\n");
	return (0);
}

/// @brief Shift down all elements of stack a && b by 1.
/// The last element becomes the first one.
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	rrr(t_stack **a, t_stack **b, int print)
{
	if ((rra (&(*a), false) == -1) || ((rrb (&(*b), false)) == -1))
		return (-1);
	if (print == true)
		ft_printf("rrr\n");
	return (1);
}

void	reverse_rotate_both(t_data *data, t_stack *to_do)
{
	while (to_do->cost_a < 0 && to_do->cost_b < 0)
	{
		rrr(&(data->a), &(data->b), true);
		to_do->cost_a++;
		to_do->cost_b++;
	}
}
