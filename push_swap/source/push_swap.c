/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:37:14 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/06 17:37:40 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/errors.h"
#include "../includes/algorythm.h"
#include "../includes/math.h"

void	print_list(t_data *data)
{
	t_stack	*cursorA;
	t_stack	*cursorB;

    cursorA = ps_lstlast(data->a);
    cursorB = ps_lstlast(data->b);
	ft_printf("Stack before sorting :\na b\n⎻ ⎻\n");
	while (cursorA || cursorB)
	{
		if (cursorA && cursorB)
		{
			ft_printf("%i %i\n", cursorA->content, cursorB->content);
            cursorA = cursorA->previous;
            cursorB = cursorB->previous;
		}
		else if (cursorA)
		{
			ft_printf("%i NAN\n", cursorA->content);
            cursorA = cursorA->previous;
		}
		else
		{
			ft_printf("NAN %i\n", cursorB->content);
            cursorB = cursorB->previous;
		}
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
    print_list(&data);
	data_cleanup(&data);
	free(data.list);
	return (0);
}
