/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:15:43 by stripet           #+#    #+#             */
/*   Updated: 2024/04/24 14:06:09 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"
#include "../includes/math.h"
#include "../includes/push_swap.h"

static void	reset_moves(t_data *data)
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

static void	add_to_moves(char **moves, char *instruction, int *steps)
{
	char	*temp;

	temp = *moves;
	*moves = ft_strjoin(*moves, instruction);
	if (temp)
		free(temp);
	*steps += 1;
}

static	int	get_to_top(t_stack *element)
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

static int	arrange_middle(t_data *data, t_stack *element)
{
	t_stack	*cursor;
	int		result;
	int		counter;

	result = 0;
	counter = 0;
	// add_to_moves(&(element->moves), "rb ", &result);
	cursor = ps_lstlast(data->b);
	while (element->content < cursor->content)
	{
		add_to_moves(&(element->moves), "rb ", &result);
		cursor = cursor->previous;
		counter++;
	}
	add_to_moves(&(element->moves), "pb ", &result);
	while (counter > 0)
	{
		add_to_moves(&(element->moves), "rrb ", &result);
		counter--;
	}
	return (result);
}

static int	moves_to_b(t_data *data, t_stack *element)
{
	int		steps;
	t_stack	*cursor;

	steps = 0;
	cursor = element;
	if (!is_rsorted(data->b) && ps_lstsize(data->b) == 2)
		add_to_moves(&(element->moves), "rb ", &steps);
	steps += get_to_top(element);
	if (element->content > data->smallest
		&& element->content < data->biggest)
		steps += arrange_middle(data, element);
	else
	{
		add_to_moves(&(element->moves), "pb ", &steps);
		if (element->content < data->smallest)
			add_to_moves(&(element->moves), "rb ", &steps);
	}
	return (steps);
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
	if (to_do->content > data->biggest)
		data->biggest = to_do->content;
	if (to_do->content < data->smallest)
		data->smallest = to_do->content;
	ft_split_free(buffer);
}

static void	push_to_b(t_data *data)
{
	t_stack	*to_push;
	t_stack	*cursor;

	if (data->b->content > data->b->next->content)
	{
		data->biggest = data->b->content;
		data->smallest = data->b->next->content;
	}
	else
	{
		data->biggest = data->b->next->content;
		data->smallest = data->b->content;
	}
	while (ps_lstsize(data->a) > 3)
	{
		to_push = ps_lstlast(data->a);
		cursor = ps_lstlast(data->a)->previous;
		while (cursor)
		{
			free(to_push->moves);
			to_push->moves = NULL;
			if (moves_to_b(data, cursor) < moves_to_b(data, to_push))
				to_push = cursor;
			cursor = cursor->previous;
		}
		ex_moves(data, to_push);
		reset_moves(data);
		
		ft_printf("after one of the ex_moves");
		print_list(data);
	}
}

void	prepare_stack(t_data *data)
{
	if (ps_lstsize(data->a) == 1 || is_sorted(data->a))
		return ;
	if (is_rsorted(data->a))
	{
		while (!is_sorted(data->a))
			ra(&(data->a));
		return ;
	}
	pb(&(data->a), &(data->b));
	
	ft_printf("after first pb");
	print_list(data);
	
	pb(&(data->a), &(data->b));
	
	ft_printf("after second pb");
	print_list(data);

	push_to_b(data);
}
