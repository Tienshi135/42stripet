/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:46:23 by stripet           #+#    #+#             */
/*   Updated: 2024/04/15 14:24:35 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/quick_sort.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *array, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[end]);
	return (i + 1);
}

void	quicksort(int *array, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, start, end);
		quicksort(array, start, pivot_index - 1);
		quicksort(array, pivot_index + 1, end);
	}
}

int	*stack_dup_to_arr(t_stack *stack)
{
	t_stack	*buffer;
	int		*array;
	int		i;

	i = 0;
	buffer = stack;
	array = ft_calloc(sizeof(int), ps_lstsize(stack));
	if (!array)
		return (NULL);
	while (buffer)
	{
		array[i] = buffer->content;
		buffer = buffer->next;
		i++;
	}
	return (array);
}

void	set_index(t_stack **stack, int *array)
{
	t_stack	*cursor;
	int		i;

	cursor = *stack;
	while (cursor)
	{
		i = 0;
		while (array[i])
		{
			if (array[i] == cursor->content)
			{
				cursor->index = i;
				break ;
			}
			i++;
		}
		cursor = cursor->next;
	}
}
