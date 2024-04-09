/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:37:14 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/09 15:25:20 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/swap.h"
#include "../includes/rotate.h"
#include "../includes/reverse.h"
#include "../includes/push.h"
#include "../includes/errors.h"
#include "../libft/libft.h"

int	is_unique(t_data data, char *str)
{
	t_stack	*cursor;

	cursor = data.a;
	while (cursor)
	{
		if (cursor->content == ft_atoi(str))
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

void	data_cleanup(t_data data)
{
	ps_lst_free(data.a);
	ps_lst_free(data.b);
}

void	stack_init(t_data *data, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if ((ft_isnum(argv[i]) == 1) || (ft_atoi(argv[i]) < 0)
			|| (is_unique(*data, argv[i]) == 1))
		{
			data_cleanup(*data);
			msg(bad_lst);
		}
		ps_lstadd_back(&(data->a), ps_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		msg(bad_args);
	ft_bzero(&data, sizeof(data));
	stack_init(&data, argv);
	pb(&(data.a), &(data.b));
	pa(&(data.a), &(data.b));
	ra(&(data.a));
	rb(&(data.b));
	sa(&(data.a));
	sb(&(data.b));
	rra(&(data.a));
	rrb(&(data.b));
	return (argc);
}
