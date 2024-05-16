/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:00:03 by stripet           #+#    #+#             */
/*   Updated: 2024/05/16 13:06:09 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILS_H
# define SORT_UTILS_H
# include "../includes/structures.h"

void	sort_3(t_stack **stack);
void	sort_small_stack(t_data *data);
void	shift_stack(t_data *data);

#endif