/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:46:12 by stripet           #+#    #+#             */
/*   Updated: 2024/05/03 15:55:39 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list_utils2.h"

void	set_big_small(t_data *data)
{
	t_stack	*cursor;
	int		big;
	int		small;

	small = data->smallest;
	big = data->biggest;
	cursor = data->b;
	while (cursor)
	{
		if (cursor->content > big)
			big = cursor->content;
		if (cursor->content < small)
			small = cursor->content;
		cursor = cursor->next;
	}
	data->biggest = big;
	data->smallest = small;
}

void	reset_moves(t_data *data)
{
	t_stack	*cursor;

	cursor = data->a;
	while (cursor)
	{
		if (cursor->moves)
		{
			free(cursor->moves);
			cursor->moves = NULL;
		}
		cursor = cursor->next;
	}
	cursor = data->b;
	while (cursor)
	{
		if (cursor->moves)
		{
			free(cursor->moves);
			cursor->moves = NULL;
		}
		cursor = cursor->next;
	}
}

void	add_to_moves(char **moves, char *instruction, int *steps)
{
	char	*temp;

	temp = *moves;
	*moves = ft_strjoin(*moves, instruction);
	if (temp)
		free(temp);
	*steps += 1;
}

void	ex_moves(t_data *data, t_stack *to_do)
{
	char	**buffer;
	int		i;

	buffer = ft_split(to_do->moves, ' ');
	i = 0;
	while (buffer[i])
	{
		if (ft_strncmp(buffer[i], "pa", ft_strlen(buffer[i])) == 0)
			pa(&(data->a), &(data->b));
		else if (ft_strncmp(buffer[i], "pb", ft_strlen(buffer[i])) == 0)
			pb(&(data->a), &(data->b));
		else if (ft_strncmp(buffer[i], "ra", ft_strlen(buffer[i])) == 0)
			ra(&(data->a));
		else if (ft_strncmp(buffer[i], "rb", ft_strlen(buffer[i])) == 0)
			rb(&(data->b));
		else if (ft_strncmp(buffer[i], "rra", ft_strlen(buffer[i])) == 0)
			rra(&(data->a));
		else if (ft_strncmp(buffer[i], "rrb", ft_strlen(buffer[i])) == 0)
			rrb(&(data->b));
		i++;
	}
	ft_split_free(buffer);
}

int	get_to_top(t_stack *element)
{
	t_stack	*cursor;
	int		counter[3];

	ft_memset(counter, 0, sizeof(counter));
	cursor = element;
	while (cursor->next)
	{
		counter[0]++;
		cursor = cursor->next;
	}
	cursor = element;
	while (cursor)
	{
		counter[1]++;
		cursor = cursor->previous;
	}
	while ((counter[0]-- > 0) && (counter[1]-- > 0))
	{
		if (counter[0] < counter[1])
			add_to_moves(&(element->moves), "ra ", &(counter[2]));
		else
			add_to_moves(&(element->moves), "rra ", &(counter[2]));
	}
	return (counter[2]);
}
