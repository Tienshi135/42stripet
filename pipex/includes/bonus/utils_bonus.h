/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:13:26 by stripet           #+#    #+#             */
/*   Updated: 2024/04/03 18:08:03 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H
# include "../../includes/bonus/structures_bonus.h"
# include <unistd.h>
# include "../../libft/libft.h"
# include <stdio.h>

void	child_proccess(t_data data, char *cmd);
void	last_cmd(t_data data, char *cmd);

#endif