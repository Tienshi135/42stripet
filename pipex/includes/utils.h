/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:13:26 by stripet           #+#    #+#             */
/*   Updated: 2024/03/05 12:52:34 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../includes/structures.h"
# include <unistd.h>
# include "../libft/libft.h"
#	include <stdio.h>

void	childpipexlast(t_data data, char *cmd);
void	childpipexfirst(t_data data, char *cmd);

#endif