/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:14:50 by stripet           #+#    #+#             */
/*   Updated: 2023/10/13 13:18:22 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>


/// @brief Gives the absolute value of n
/// @param n 
/// @return int n as absolute vaue or -1 on error
int	ft_abs(int n)
{
	if (n == INT_MIN)
		return (-1);
	if (n < 0)
		n *= -1;
	return (n);
}
