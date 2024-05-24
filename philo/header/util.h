/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:39:46 by stripet           #+#    #+#             */
/*   Updated: 2024/05/24 14:50:46 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "stdlib.h"
# include "../header/structure.h"
# include "stdio.h"

int		ph_atoi(const char *str);
void	mutex_init(t_data *data);
int		get_current_time(void);

#endif