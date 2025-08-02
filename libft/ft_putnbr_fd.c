/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:25:03 by tienshi           #+#    #+#             */
/*   Updated: 2023/09/22 12:33:41 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

static int	nb_len(int c)
{
	int	returnvalue;

	returnvalue = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		returnvalue++;
	while (c != 0)
	{
		c /= 10;
		returnvalue++;
	}
	return (returnvalue);
}

/// @brief writes int n to fd
/// @param c 
/// @param fd 
int	ft_putnbr_fd(int n, int fd)
{
	int		len;
	char	c;

	len = nb_len(n);
	if (fd >= 0)
	{
		if (n == INT_MIN)
			return (write(fd, "-2147483648", 11));
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		c = '0' + (n % 10);
		write(fd, &c, 1);
	}
	return (len);
}
