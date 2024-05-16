/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:08:32 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/16 13:35:38 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_H
# define REVERSE_H
# include "../includes/structures.h"

int		rra(t_stack **a, int print);
int		rrb(t_stack **b, int print);
int		rrr(t_stack **a, t_stack **b, int print);
void	reverse_rotate_both(t_data *data, t_stack *to_do);

#endif