/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:46:02 by stripet           #+#    #+#             */
/*   Updated: 2024/05/06 13:41:06 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/push_swap_checker_bonus.h"
#include "../../includes/structures.h"
#include "../../includes/bonus/push_bonus.h"
#include "../../includes/bonus/reverse_bonus.h"
#include "../../includes/bonus/rotate_bonus.h"
#include "../../includes/bonus/swap_bonus.h"
#include "../../libft/libft.h"
#include "../../includes/bonus/error_bonus.h"
#include "../../includes/utils.h"
#include "unistd.h"

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

int	execute(t_data *data, char	*buffer)
{
	if (ft_strncmp(buffer, "pa", 2) == 0)
		pa_bonus(&(data->a), &(data->b));
	else if (ft_strncmp(buffer, "pb", 2) == 0)
		pb_bonus(&(data->a), &(data->b));
	else if (ft_strncmp(buffer, "rra", 3) == 0)
		rra_bonus(&(data->a));
	else if (ft_strncmp(buffer, "rrb", 3) == 0)
		rrb_bonus(&(data->b));
	else if (ft_strncmp(buffer, "rrr", 3) == 0)
		rrr_bonus(&(data->a), &(data->b));
	else if (ft_strncmp(buffer, "ra", 2) == 0)
		ra_bonus(&(data->a));
	else if (ft_strncmp(buffer, "rb", 2) == 0)
		rb_bonus(&(data->b));
	else if (ft_strncmp(buffer, "rr", 2) == 0)
		rr_bonus(&(data->a), &(data->b));
	else if (ft_strncmp(buffer, "sa", 2) == 0)
		sa_bonus(&(data->a));
	else if (ft_strncmp(buffer, "sb", 2) == 0)
		sb_bonus(&(data->a));
	else if (ft_strncmp(buffer, "ss", 2) == 0)
		ss_bonus(&(data->a), &(data->b));
	else
		return (-1);
	return (0);
}

void	get_instructions(t_data *data)
{
	char	*buffer;

	buffer = get_next_line(STDIN_FILENO);
	while (buffer)
	{
		if (execute(data, buffer) == -1)
		{
			free(buffer);
			error(data);
		}
		free(buffer);
		buffer = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		error(&data);
	data.list = ft_argv_to_str(argc, argv);
	stack_init(&data, data.list);
	get_instructions(&data);
	if (is_sorted(data.a))
		ft_printf("OK !\n");
	else
		ft_printf("KO :(\n");
}
