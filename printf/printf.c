/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:12:43 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/18 11:16:20 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>

int	ft_printf(const char *string, ...)
{
	va_list	arguments;
	int		counter;

	counter = 0;
	va_start(arguments, string);
	return (counter);
}
