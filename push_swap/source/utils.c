/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:39:15 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/07 15:36:17 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../includes/math.h"

void	data_cleanup(t_data *data)
{
	if (data->a)
		ps_lst_free(data->a);
	if (data->b)
		ps_lst_free(data->b);
	if (data->dupa)
		ps_lst_free(data->dupa);
	if (data->dupb)
		ps_lst_free(data->dupb);
}

void	ps_lst_free(t_stack *tofree)
{
	t_stack	*cursor;
	t_stack	*freeable;

	cursor = tofree;
	while (cursor)
	{
		freeable = cursor;
		cursor = cursor->next;
		free(freeable);
	}
}

int	is_valid(t_data *data, char *str)
{
	t_stack	*cursor;

	cursor = data->a;
	if (!ft_isint(str))
		return (0);
	while (cursor)
	{
		if (cursor->content == ft_atoi(str))
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

void	sort_init(t_data *data)
{
	pb(&(data->a), &(data->b));
	pb(&(data->a), &(data->b));
	if (!is_rsorted(data->b) && ps_lstsize(data->b) == 2)
		rb(&(data->b));
	data->dupa = ps_lstcopy(data->a);
	data->dupb = ps_lstcopy(data->b);
}

t_stack	*ps_lstcopy(t_stack *src)
{
	t_stack	*cursor;
	t_stack	*dst;

	ft_bzero(&dst, sizeof(t_stack *));
	cursor = src;
	while (cursor)
	{
		ps_lstadd_back(&dst, ps_lstnew(cursor->content));
		cursor = cursor->next;
	}
	return (dst);
}
