/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:37:14 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/12 10:23:55 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/swap.h"
#include "../includes/rotate.h"
#include "../includes/reverse.h"
#include "../includes/push.h"
#include "../includes/errors.h"
#include "../libft/libft.h"

void	print_list(t_stack *a)
{
	t_stack	*cursor;

	cursor = a;
	while (cursor)
	{
		ft_printf("%i\n", cursor->content);
		cursor = cursor->next;
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
		error();
	}
	while (buffer[i])
	{
		if (is_valid(data, buffer[i]))
			ps_lstadd_front(&(data->a), ps_lstnew(ft_atoi(buffer[i])));
		else
		{
			data_cleanup(*data);
			ft_split_free(buffer);
			error();
		}
		i++;
	}
	ft_printf("Finished stack allocation !\n");
	ft_split_free(buffer);
}

static void	wait_prompt(t_data *data)
{
	char	*buffer;
	char	*temp;

	temp = NULL;
	ft_printf("Enter a list of integers\n");
	while (!temp)
	{
		temp = get_next_line(STDIN_FILENO);
	}
	buffer = ft_substr(temp, 0, ft_strlen(temp) - 1);
	free (temp);
	stack_init(&(*data), buffer);
	free(buffer);
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
	print_list(data.a);
	data_cleanup(data);
	return (0);
}
