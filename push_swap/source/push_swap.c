/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:37:14 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/10 10:37:53 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/swap.h"
#include "../includes/rotate.h"
#include "../includes/reverse.h"
#include "../includes/push.h"
#include "../includes/errors.h"
#include "../libft/libft.h"

int	is_valid(char *str)
{
	return (0);
}

void	data_cleanup(t_data data)
{
	if (data.a)
		ps_lst_free(data.a);
	if (data.b)
		ps_lst_free(data.b);
}

void	stack_init(t_data *data, char *list)
{
	char	**buffer;

	buffer = ft_split(list, ' ');
	if (!buffer || *buffer == list || is_valid(list))
		error();
}

void	wait_prompt(t_data *data)
{
	char	*buffer;

	buffer = NULL;
	ft_printf("Enter a list of integers\n");
	while (!buffer)
	{
		buffer = get_next_line(STDIN_FILENO);
	}
	stack_init(data, buffer);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	if (argc != 2)
		wait_prompt(&data);
	else
		stack_init(&data, argv[1]);
	return (0);
}
