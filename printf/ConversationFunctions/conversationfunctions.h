/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversationfunctions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:18:30 by tienshi           #+#    #+#             */
/*   Updated: 2023/10/18 10:18:44 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSATIONFUNCTIONS_H
# define CONVERSATIONFUNCTIONS_H

# include <unistd.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		printchar(int c);
int		printstring(char *str);
int		printpointer(unsigned long long c);
int		printdecimal(int c);
int		printinteger(int c);
int		printunsigneddecimal(unsigned int c);
int		printhexadecimall(unsigned int c);
int		printhexadecimalu(unsigned int c);

#endif