/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:35:22 by stripet           #+#    #+#             */
/*   Updated: 2024/05/30 12:05:57 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../header/structure.h"
# include "../header/error.h"
# include "../header/util.h"

void		init_data(t_data *data, int argc, char **argv);
void		init_mutexes(t_data *data);

#endif