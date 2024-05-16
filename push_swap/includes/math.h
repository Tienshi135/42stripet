/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:25:47 by stripet           #+#    #+#             */
/*   Updated: 2024/05/16 13:10:24 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
# include "../includes/structures.h"
# include "../includes/utils.h"
# include "limits.h"

int		is_sorted(t_stack *stack);
int		is_rsorted(t_stack *stack);
t_stack	*find_biggest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);
void	get_cost(t_data *data);

#endif