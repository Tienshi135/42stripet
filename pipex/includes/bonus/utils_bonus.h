/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:13:26 by stripet           #+#    #+#             */
/*   Updated: 2024/03/20 15:56:49 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "../../includes/bonus/structures_bonus.h"
# include <unistd.h>
# include "../../libft/libft.h"
# include <stdio.h>

void	childpipexlast(t_data data, char *cmd);
void	childpipexfirst(t_data data, char *cmd);

#endif