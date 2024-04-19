/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:37:14 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/19 10:22:48 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/swap.h"
#include "../includes/rotate.h"
#include "../includes/reverse.h"
#include "../includes/push.h"
#include "../includes/errors.h"
#include "../libft/libft.h"
#include "../includes/math.h"
#include "../includes/quick_sort.h"
#include "../includes/algorythm.h"

void	print_list(t_data *data)
{
	t_stack	*cursora;
	t_stack	*cursorb;

	cursora = ps_lstlast(data->a);
	cursorb = ps_lstlast(data->b);
	ft_printf("Stack before sorting :\na b\n⎻ ⎻\n");
	while (cursora || cursorb)
	{
		if (cursora && cursorb)
		{
			ft_printf("%i %i\n", cursora->content, cursorb->content);
			cursora = cursora->previous;
			cursorb = cursorb->previous;
		}
		else if (cursora)
		{
			ft_printf("%i NAN\n", cursora->content);
			cursora = cursora->previous;
		}
		else if (cursorb)
		{
			ft_printf("NAN %i\n", cursorb->content);
			cursorb = cursorb->previous;
		}
	}
}

static void	stack_sort(t_data *data)
{
	int	*array;

	array = stack_dup_to_arr(data->a);
	quicksort(array, 0, ps_lstsize(data->a) - 1);
	set_index(&(data->a), array);
	prepare_stack(data);
	print_list(data);
	free(array);
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
	while (buffer[i])
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
	print_list(&data);
	stack_sort(&data);
	data_cleanup(&data);
	free(data.list);
	return (0);
}
