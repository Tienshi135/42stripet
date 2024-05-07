/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:46:21 by stripet           #+#    #+#             */
/*   Updated: 2024/05/07 15:14:53 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS2_H
# define LIST_UTILS2_H
# include "../includes/structures.h"
# include "../includes/swap.h"
# include "../includes/rotate.h"
# include "../includes/reverse.h"
# include "../includes/push.h"

void	reset_moves(t_data *data);
void	add_to_moves(char **moves, char *instruction, int *steps);
void	ex_moves(t_data *data, t_stack *to_do);
int		get_to_top(t_stack *element);

#endif