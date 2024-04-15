/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:46:48 by stripet           #+#    #+#             */
/*   Updated: 2024/04/15 14:25:14 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SORT_H
# define QUICK_SORT_H
# include "../includes/structures.h"
# include "../includes/utils.h"

void	quicksort(int *array, int start, int end);
int		*stack_dup_to_arr(t_stack *stack);
void	set_index(t_stack **stack, int *array);

#endif