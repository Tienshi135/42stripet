/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:39:46 by stripet           #+#    #+#             */
/*   Updated: 2024/05/20 11:40:30 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "stdlib.h"
# include "../header/structure.h"
# include "stdio.h"

int		ph_atoi(const char *str);
void	free_philo(t_data *data);

#endif