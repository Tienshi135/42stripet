/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:25:47 by stripet           #+#    #+#             */
/*   Updated: 2024/04/12 14:27:26 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
# include "../includes/structures.h"

int	ps_max(t_stack *stack);
int	ps_min(t_stack *stack);
int	is_sorted(t_stack *stack);
int	is_rsorted(t_stack *stack);
int	ps_average(t_stack *stack);

#endif