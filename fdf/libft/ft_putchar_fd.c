/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:44:34 by tienshi           #+#    #+#             */
/*   Updated: 2023/09/22 12:16:50 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


/// @brief writes char c to fd
/// @param c 
/// @param fd 
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
