/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:39:15 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/05 09:57:38 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

t_stack	*ps_lstnew(int value)
{
	t_stack	*buffer;

	buffer = (t_stack *) ft_calloc(sizeof(t_stack), 1);
	if (!buffer)
		return (NULL);
	buffer->content = value;
	return (buffer);
}

int	ps_lstsize(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*ps_lstlast(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ps_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ps_lstlast(*lst);
	last->next = new;
	new->previous = last;
}

void	ps_lst_free(t_stack *tofree)
{
	t_stack	*cursor;

	cursor = tofree->next;
	while (cursor)
	{
		free(tofree);
		tofree = cursor;
		cursor = cursor->next;
	}
	free(tofree);
}
/*
/// @brief Take the first element at the top of b and put it at the top of a.
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	pa(t_stack a, t_stack b)
{

}

/// @brief Take the first element at the top of a and put it at the top of b.
/// @param t_stack a 
/// @param t_stack b 
/// @return 1 on success -1 on failure
int	pb(t_stack a, t_stack b)
{
	
}
*/