/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:37:14 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/05 09:54:29 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*test;

	test = ps_lstnew(10);
	ps_lstadd_back(&test, ps_lstnew(20));
	ps_lstadd_back(&test, ps_lstnew(30));
	sa(&test);
	ps_lst_free(test);
	ft_printf("%s\n", argv[0]);
	return (argc);
}
