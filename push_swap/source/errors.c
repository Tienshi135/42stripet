/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:20:53 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/10 11:10:04 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors.h"
#include "../libft/libft.h"

void	msg(int code)
{
	if (code == bad_args)
		ft_printf("bad number of args, expected 2+ unique positive ints\n");
	if (code == bad_lst)
		ft_printf(("List format is incorrect, expected unique positive ints\n"));
	exit (code);
}

void	error(void)
{
	write(STDERR_FILENO, "Error !\n", 8);
	exit (-1);
}
