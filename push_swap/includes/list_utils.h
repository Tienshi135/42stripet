/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:30:18 by stripet           #+#    #+#             */
/*   Updated: 2024/05/03 15:50:17 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H
# include "../includes/structures.h"
# include "../includes/list_utils2.h"

int		ps_lstsize(t_stack *stack);
t_stack	*ps_lstlast(t_stack *lst);
t_stack	*ps_lstnew(int value);
void	ps_lstadd_back(t_stack **lst, t_stack *new);
void	ps_lstadd_front(t_stack **lst, t_stack *new);

#endif