/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:15:43 by stripet           #+#    #+#             */
/*   Updated: 2024/04/29 13:29:25 by stripet          ###   ########.fr       */
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

static void	sort_3(t_stack **stack)
{
	t_stack	*nodes[3];

	nodes[0] = ps_lstlast(*stack);
	nodes[1] = nodes[0]->previous;
	nodes[2] = *stack;

	while (!is_sorted(*stack))
	{
		if (nodes[0] > nodes[2])
		{
			ra(stack);
			sa(stack);
		}
		if (nodes[0] > nodes[1])
			sa(stack);
		if (nodes[1] > nodes[2])
		{
			rra(stack);
			sa(stack);
		}
	}

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

static void	set_big_small(t_data *data)
{
	t_stack	*cursor;
	int		big;
	int		small;

	small = ps_lstsize(data->b);
	big = 0;
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

static void	push_to_b(t_data *data)
{
	t_stack	*to_push;
	t_stack	*cursor;

	pb(&(data->a), &(data->b));
	pb(&(data->a), &(data->b));
	while (ps_lstsize(data->a) > 3)
	{
		to_push = ps_lstlast(data->a);
		cursor = ps_lstlast(data->a)->previous;
		while (cursor)
		{
			set_big_small(data);
			reset_moves(data);
			if (moves_to_b(data, cursor) < moves_to_b(data, to_push))
				to_push = cursor;
			cursor = cursor->previous;
		}
		ex_moves(data, to_push);
	}
}

static void	should_swap(t_data *data)
{
	t_stack	*cursor;
	t_stack	*cursorb;

	cursor = data->a;
	cursorb = ps_lstlast(data->b);

	if (cursorb->content < data->a->content
		&& cursorb->content < ps_lstlast(data->a)->content)
	{
		while (cursor->content < ps_lstlast(data->a)->content
			&& cursor->content > cursorb->content)
		{
			rra(&(data->a));
			cursor = data->a;
		}
	}
	else
	{
		while (cursor->content > cursorb->content)
		{
			rra(&(data->a));
			cursor = data->a;
		}
	}
}


static void	push_to_a(t_data *data)
{
	while (ps_lstsize(data->b) > 0)
	{
		should_swap(data);
		pa(&(data->a), &(data->b));
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
	push_to_b(data);
	sort_3(&(data->a));
	push_to_a(data);
}
