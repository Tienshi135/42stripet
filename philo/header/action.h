/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:55:07 by stripet           #+#    #+#             */
/*   Updated: 2024/05/30 12:06:26 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include "../header/structure.h"
# include "../header/util.h"

void	take_forks(t_philosopher *philo);
void	eat(t_philosopher *philo);
void	drop_forks(t_philosopher *philo);
void	sleeping(t_philosopher *philo);

#endif