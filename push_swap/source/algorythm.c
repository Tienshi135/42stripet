/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:12:00 by stripet           #+#    #+#             */
/*   Updated: 2024/04/29 13:28:29 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/algorythm.h"
#include "../includes/push_swap.h"

static int	find_median(t_stack *a)
{
	t_stack	*cursor;

	cursor = ps_lstlast(a);
	while (cursor)
	{
		if (cursor->sort_index == ps_lstsize(a) / 2)
			return (cursor->content);
		cursor = cursor->previous;
	}
	return (0);
}

void	moves_free(t_stack *tofree)
{
	t_stack	*cursor;

	cursor = ps_lstlast(tofree);
	while (cursor)
	{
		if (cursor->moves)
			free(cursor->moves);
		cursor = cursor->previous;
	}
}

void	ex_moves(t_stack **stack, t_stack *to_do)
{
	char	**buffer;
	int		i;

	buffer = ft_split(to_do->moves, ' ');
	i = 0;
	while (buffer[i])
	{
		if (ft_strncmp(buffer[i], "ra", ft_strlen(buffer[i])) == 0)
			ra(stack);
		else if (ft_strncmp(buffer[i], "rra", ft_strlen(buffer[i])) == 0)
			rra(stack);
		i++;
	}
	ft_split_free(buffer);
}

// static int	moves_counter(t_stack *stack, t_stack *start, int end)
// {
// 	char	*buffer;
// 	int		result;

// 	buffer = NULL;
// 	if (start->index == end)
// 		return (0);
// }

static int	to_top_counter(t_stack *stack, t_stack *start)
{
	char	*temp;
	int		result;

	start->moves = NULL;
	result = 0;
	if (start->index == 0)
		return (0);
	if (ps_lstsize(stack) - start->index < start->index)
	{
		while (result < ps_lstsize(stack) - start->index)
		{
			temp = start->moves;
			start->moves = ft_strjoin(temp, "rra ");
			if (temp)
				free(temp);
			result++;
		}
	}
	else
	{
		while (result < start->index)
		{
			temp = start->moves;
			start->moves = ft_strjoin(temp, "ra ");
			if (temp)
				free(temp);
			result++;
		}
	}
	return (result);
}

void	prepare_stack(t_data *data)
{
	t_stack	*cursor;
	t_stack	*to_push;
	int		median;
	int		temp;
	int		ret_val;

	median = find_median(data->a);
	temp = ps_lstsize(data->a) + 1;
	while (ps_lstsize(data->a) > ps_lstsize(data->b) + 1)
	{
		cursor = ps_lstlast(data->a);
		while (cursor)
		{
			if (cursor->content < median)
			{
				ret_val = to_top_counter(data->a, cursor);
				if (ret_val < temp && ret_val != 0)
					to_push = cursor;
			}
			cursor = cursor->previous;
		}
		ex_moves(&(data->a), to_push);
		moves_free(data->a);
		pb(&(data->a), &(data->b));
	}
}
