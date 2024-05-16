/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:46:02 by stripet           #+#    #+#             */
/*   Updated: 2024/05/16 15:05:48 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/push_swap_checker_bonus.h"
#include "../../includes/utils.h"

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
	if (ft_strncmp(buffer, "pa", ft_strlen(buffer)) == 0)
		pa(&(data->a), &(data->b), false);
	else if (ft_strncmp(buffer, "pb", ft_strlen(buffer)) == 0)
		pb(&(data->a), &(data->b), false);
	else if (ft_strncmp(buffer, "rra", ft_strlen(buffer)) == 0)
		rra(&(data->a), false);
	else if (ft_strncmp(buffer, "rrb", ft_strlen(buffer)) == 0)
		rrb(&(data->b), false);
	else if (ft_strncmp(buffer, "rrr", ft_strlen(buffer)) == 0)
		rrr(&(data->a), &(data->b), false);
	else if (ft_strncmp(buffer, "ra", ft_strlen(buffer)) == 0)
		ra(&(data->a), false);
	else if (ft_strncmp(buffer, "rb", ft_strlen(buffer)) == 0)
		rb(&(data->b), false);
	else if (ft_strncmp(buffer, "rr", ft_strlen(buffer)) == 0)
		rr(&(data->a), &(data->b), false);
	else if (ft_strncmp(buffer, "sa", ft_strlen(buffer)) == 0)
		sa(&(data->a), false);
	else if (ft_strncmp(buffer, "sb", ft_strlen(buffer)) == 0)
		sb(&(data->a), false);
	else if (ft_strncmp(buffer, "ss", ft_strlen(buffer)) == 0)
		ss(&(data->a), &(data->b), false);
	else
		error(data);
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
