/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:15:25 by stripet           #+#    #+#             */
/*   Updated: 2023/11/14 09:04:37 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	conversation(va_list arguments, const char c)
{
	int	returnvalue;

	returnvalue = 0;
	if (c == 'c')
		returnvalue += ft_putchar_fd(va_arg(arguments, int), STDOUT_FILENO);
	else if (c == 's')
		returnvalue += ft_putstr_fd(va_arg(arguments, char *), STDOUT_FILENO);
	else if (c == 'p')
		returnvalue += printpointer(va_arg(arguments, unsigned long long));
	else if (c == 'd')
		returnvalue += ft_putnbr_fd(va_arg(arguments, int), STDOUT_FILENO);
	else if (c == 'i')
		returnvalue += ft_putnbr_fd(va_arg(arguments, int), STDOUT_FILENO);
	else if (c == 'u')
		returnvalue += printunsigneddecimal(va_arg(arguments, unsigned int));
	else if (c == 'x')
		returnvalue += printhexadecimall(va_arg(arguments, unsigned int));
	else if (c == 'X')
		returnvalue += printhexadecimalu(va_arg(arguments, unsigned int));
	else if (c == '%')
		returnvalue += write(1, "%", 1);
	return (returnvalue);
}

/// @brief Writes char * string to STDOUT.
/// @param string 
/// @param ...
/// @return number of bytes written
int	ft_printf(const char *string, ...)
{
	va_list	arguments;
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	va_start(arguments, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			counter += conversation(arguments, string[i + 1]);
			i++;
		}
		else
			counter += write(1, &string[i], 1);
		i++;
	}
	return (counter);
}
