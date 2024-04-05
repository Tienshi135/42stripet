/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:37:14 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/05 11:15:40 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/swap.h"
#include "../includes/rotate.h"
#include "../includes/reverse.h"
#include "../includes/push.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*test;
	t_stack	*test2;

	test = ps_lstnew(10);
	ps_lstadd_back(&test, ps_lstnew(20));
	ps_lstadd_back(&test, ps_lstnew(30));
	test2 = ps_lstnew(40);
	ps_lstadd_back(&test2, ps_lstnew(50));
	ps_lstadd_back(&test2, ps_lstnew(60));
	pb(&test, &test2);
	ps_lst_free(test);
	ps_lst_free(test2);
	ft_printf("%s\n", argv[0]);
	return (argc);
}
