/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:37:14 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/16 13:05:55 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"
#include "../includes/algorythm.h"
#include "../includes/math.h"

void	index_init(t_stack *a, int stack_size)
{
	t_stack	*cursor;
	t_stack	*biggest;
	int		temp;

	while (stack_size-- > 0)
	{
		cursor = a;
		temp = INT_MIN;
		biggest = NULL;
		while (cursor)
		{
			if (cursor->content == INT_MIN && cursor->index == 0)
				cursor->index = 1;
			if (cursor->content > temp && cursor->index == 0)
			{
				temp = cursor->content;
				biggest = cursor;
				cursor = a;
			}
			else
				cursor = cursor->next;
		}
		if (biggest != NULL)
			biggest->index = stack_size;
	}
}

static void	stack_init(t_data *data, char *list)
{
	char	**buffer;
	int		i;

	i = 0;
	buffer = ft_split(list, ' ');
	if (!buffer || ft_strncmp(*buffer, list, ft_strlen(list)) == 0)
	{
		if (buffer)
			ft_split_free(buffer);
		error(data);
	}
	while (buffer && buffer[i])
	{
		if (is_valid(data, buffer[i]))
			ps_lstadd_front(&(data->a), ps_lstnew(ft_atoi(buffer[i])));
		else
		{
			data_cleanup(data);
			ft_split_free(buffer);
			error(data);
		}
		i++;
	}
	ft_split_free(buffer);
	index_init(data->a, ps_lstsize(data->a));
}

static void	wait_prompt(t_data *data)
{
	char	*temp;

	temp = NULL;
	ft_printf("Enter a list of integers\n");
	while (!temp)
	{
		temp = get_next_line(STDIN_FILENO);
	}
	data->list = ft_strtrim(temp, "\n");
	free (temp);
	temp = data->list;
	data->list = ft_strtrim(temp, "\"");
	free(temp);
	stack_init(&(*data), data->list);
}

void	sort_big_stack(t_data *data)
{
	if (ps_lstsize(data->a) == 1 || is_sorted(data->a))
		return ;
	push_to_b(data);
	sort_3(&(data->a));
	push_to_a(data);
	shift_stack(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	if (argc < 2)
		wait_prompt(&data);
	else
	{
		data.list = ft_argv_to_str(argc, argv);
		stack_init(&data, data.list);
	}
	if (ps_lstsize(data.a) < 5)
		sort_small_stack(&data);
	else
		sort_big_stack(&data);
	data_cleanup(&data);
	free(data.list);
	return (0);
}
