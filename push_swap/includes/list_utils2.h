/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:46:21 by stripet           #+#    #+#             */
/*   Updated: 2024/05/16 13:29:22 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS2_H
# define LIST_UTILS2_H
# include "structures.h"
# include "swap.h"
# include "rotate.h"
# include "reverse.h"
# include "push.h"
# include "math.h"

void	set_position(t_stack *stack);
int		set_target(t_data *data, int index_b);
void	do_costa(t_data *data, t_stack *to_do);
void	do_costb(t_data *data, t_stack *to_do);

#endif