/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:37:14 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/09 09:40:24 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/swap.h"
#include "../includes/rotate.h"
#include "../includes/reverse.h"
#include "../includes/push.h"
#include "../includes/errors.h"
#include "../libft/libft.h"

void	data_cleanup(t_data data)
{
	ps_lst_free(data.a);
	ps_lst_free(data.b);
}

int	list_parse(t_data *data, char **argv)
{
	int	i;

	i = 1;
	data->a = ft_calloc(1, sizeof(t_stack *));
	data->b = ft_calloc(1, sizeof(t_stack *));
	while (argv[i])
	{
		if ((isnum(argv[i]) == 1) || (ft_atoi(argv[i]) < 0)
			|| (isunique(data, argv[i]) == 1))
		{
			data_cleanup(*data);
			msg(bad_lst);
		}
		ps_lstadd_back(&(data->a), ps_lstnew(argv[i]));
	}
}


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		msg(bad_args);
	ft_bzero(&data, sizeof(data));
	if (list_parse(&data, argv) == 1)
		msg(bad_lst);
	return (argc);
}
