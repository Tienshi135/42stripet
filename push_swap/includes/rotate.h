/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:39:52 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/16 13:36:12 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATE_H
# define ROTATE_H
# include "../includes/structures.h"

int		ra(t_stack **a, int print);
int		rb(t_stack **b, int print);
int		rr(t_stack **a, t_stack **b, int print);
void	rotate_both(t_data *data, t_stack *to_do);

#endif