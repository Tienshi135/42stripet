/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:24:29 by stripet           #+#    #+#             */
/*   Updated: 2023/10/18 11:32:29 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 0)
	{
		ft_putnbr_fd(ft_printf("%x return value is :", 2147483647), 1);
		printf("\n");
		ft_putnbr_fd(printf("%x return value is :", 2147483647), 1);
	}
	return (0);
}
